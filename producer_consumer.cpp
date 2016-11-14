/*
 * About: Simple program implementing dummy producer-consumer paradigm
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <queue>
using namespace std;

#define MAX_JOBS 5

pthread_mutex_t lock;
pthread_cond_t cond;
queue<int> q;

void perform_job(int jobId) {
    // can have meaningful execution as per requirement
    int t = rand() % 5;
    sleep(t);
    printf("Job ID %d done, took %d sec to finish.\n", jobId, t);
}

void* consumer(void *) {
    printf("Consumer created !\n");
    while (1) {
        pthread_mutex_lock(&lock);
        while (q.empty())
            pthread_cond_wait(&cond, &lock);
        int jobId = q.front();
        q.pop();
        printf("Job ID %d disptched to worker.\n", jobId);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
        perform_job(jobId);
    }
}

void* producer(void *) {
    printf("Producer created !\n");
    while (1) {
        pthread_mutex_lock(&lock);
        while (q.size() >= MAX_JOBS)
            pthread_cond_wait(&cond, &lock);
        int jobId = 100 + rand() % 900; // could be meaningful
        printf("Job ID %d submitted for processing.\n", jobId);
        q.push(jobId);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }
}

int main(int argc, char* argv[]) {
    pthread_t prod, cons;
    int ret;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    ret = pthread_create(&cons, NULL, consumer, NULL);
    if (ret < 0)
        perror("Consumer thread could not be spawned.\n");

    ret = pthread_create(&prod, NULL, producer, NULL);
    if (ret < 0)
        perror("Producer thread could not be spawned.\n");

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
