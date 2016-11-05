/*
 * About: This example is taken from stack overflow.
 */
#include <stdio.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define SEM1_NAME "/test.mutex1"
#define SEM2_NAME "/test.mutex2"
#define SEM3_NAME "/test.mutex3"

sem_t *sem1;
sem_t *sem2;
sem_t *sem3;

int maxnum;
static int curnum = 0;

int main(int argc, char *argv[]) {
    sem1 = sem_open(SEM1_NAME, O_CREAT, 0664, 1);
    if(sem1 == (void *)-1) {
        perror("sem_open() failed ");
    }
    sem2 = sem_open(SEM2_NAME, O_CREAT, 0664, 0);
    if(sem2 == (void *)-1) {
        perror("sem_open() failed ");
    }
    sem3 = sem_open(SEM3_NAME, O_CREAT, 0664, 0);
    if(sem3 == (void *)-1) {
        perror("sem_open() failed ");
    }

    maxnum = argc > 1 ? atoi(argv[1]) : 20;

    //int segment_id = shmget(IPC_PRIVATE, segment_size,S_IRUSR|S_IWUSR);

    //curnum = (int *) shmat(segment_id, NULL, 0);
    //maxnum = curnum + 1;

    if(fork()) {
        if(fork()) {
            sem_wait(sem1);
            while(curnum <= maxnum) {
                printf("%d", curnum);
                printf(" Main \n");
                //++curnum[0];
                ++curnum;
                sem_post(sem2);
                sem_wait(sem1);
            }
            printf("Exiting Main Loop");
            sem_post(sem2);
            wait(NULL);
            //shmctl(segment_id, IPC_RMID, NULL);
        }
        else {
            sem_wait(sem3);
            while(curnum <= maxnum){
                printf("%d", curnum);
                printf(" Child 1\n");
                //++curnum[0];
                ++curnum;
                sem_post(sem1);
                sem_wait(sem3);
            }
            printf("Exiting Child 1 Loop");
            sem_post(sem1);
        }
    }
    else {
        sem_wait(sem2);
        while(curnum <= maxnum){
            printf("%d", curnum);
            printf(" Child 2\n");
            //++curnum[0];
            ++curnum;
            sem_post(sem3);
            sem_wait(sem2);
        }
        printf("Exiting Child 2 Loop");
        sem_post(sem3);
    }

    sem_close(sem1);
    sem_close(sem2);
    sem_close(sem3);

    sem_unlink(SEM1_NAME);
    sem_unlink(SEM2_NAME);
    sem_unlink(SEM3_NAME);

    /* remove shared memory segment */
    //shmctl(segment_id, IPC_RMID, NULL);

    return 0;
}
