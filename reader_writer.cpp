/*
 * About: basic implemtation of solving reader-writer problem in OS. This
 * approach 'tries' not to starve any of waiting reader/ writer. The algorithm
 * allows any number of readers if there are no writers. In case if there are
 * waiting writers, new readers are made to wait. Writers wait till current
 * readers are done with reading.
 */
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <queue>
#include <pthread.h>
using namespace std;

class rwsem {
    int r;
    pthread_mutex_t m; // protects all the accesses to rwsem
    bool block_new_readers; // true if there is writer waiting
    bool waiting_writers; // true if there is at least one writer waiting
    pthread_cond_t read_ok;
    pthread_cond_t write_ok;

public:
    rwsem() {
        r = 0;
        block_new_readers = false;
        waiting_writers = false;
        pthread_mutex_init(&m, NULL);
    }
    void read_lock();
    void read_unlock();

    void write_lock();
    void write_unlock();
};

void rwsem::read_lock() {
    pthread_mutex_lock(&m);
    if (r >= 0 && !block_new_readers) { // no writers
        r++; // grabbed rwsem
        pthread_mutex_unlock(&m);
    }
    else {
        pthread_cond_wait(&read_ok, &m); // there is a writer waiting
    }
}

void rwsem::read_unlock() {
    pthread_mutex_lock(&m);
    r--; // release read ownership
    if (r == 0) {
        // wake up writers if there are any
        pthread_cond_signal(&write_ok);
    }
    pthread_mutex_unlock(&m);
}

void rwsem::write_lock() {
    pthread_mutex_lock(&m);
    if (r == 0) {
        r--; // become write owners
        pthread_mutex_unlock(&m);
    }
    else if (r > 0) { // there are readers(r > 0)
        block_new_readers = true;
        pthread_cond_wait(&write_ok, &m);
    }
    else { // there is writer
        waiting_writers = true;
        pthread_cond_wait(&write_ok, &m);
    }
}

void rwsem::write_unlock() {
    pthread_mutex_lock(&m);
    r++; // relinquish write ownership
    if (r == 0) { // since we allow only 1 writer, this must be true;
        if (waiting_writers) {
            waiting_writers = false; // there can be more waiting
            pthread_cond_signal(&write_ok);
        }
        else {
            block_new_readers = false;
            pthread_cond_signal(&read_ok);
        }
    }
    pthread_mutex_unlock(&m);
}

void* writer(void *rw) {
    rwsem *rws = (rwsem *)rw;
    while (1) {
        // start a write operation
        rws->write_lock();
        // perform write
        rws->write_unlock();
    }
}

void* reader(void *rw) {
    rwsem *rws = (rwsem *)rw;
    while (1) {
        // start reading
        rws->read_lock();
        // perform read
        rws->read_unlock();
    }
}

int main(int argc, char* argv[]) {
    pthread_t w, r1, r2;
    rwsem *rw = new rwsem();
    pthread_create(&w, NULL, writer, rw);
    pthread_create(&r1, NULL, reader, rw);
    pthread_create(&r2, NULL, reader, rw);

    return 0;
}
