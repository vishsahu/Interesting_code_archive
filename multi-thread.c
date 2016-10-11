#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
pthread_cond_t cond;
int oddDone = 1;
int shared_var;
int cnt = 10;

void* print_even(void *foo) {
    while (cnt > 0) {
        pthread_mutex_lock(&lock);
        if (!oddDone)
            pthread_cond_wait(&cond, &lock);
        printf("cond = %d evenThread:%2d\n", cond, shared_var++);
        oddDone = 0;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
        cnt--;
    }
}

void* print_odd(void *foo) {
    while (cnt > 0) {
        pthread_mutex_lock(&lock);
        if (oddDone)
            pthread_cond_wait(&cond, &lock);
        printf("cond = %d oddThread:%2d\n", cond, shared_var++);
        oddDone = 1;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
        cnt--;
    }
}

int main() {
   pthread_t even_t, odd_t;
   int ret;

   pthread_mutex_init(&lock, NULL);
   pthread_cond_init(&cond, NULL);

   ret = pthread_create(&even_t, NULL, print_even, NULL);
   if (ret < 0) {
      printf("failed to create the thread.\n");
   }

   ret = pthread_create(&odd_t, NULL, print_odd, NULL);
   if (ret < 0) {
      printf("failed to create the thread.\n");
   }

   pthread_join(even_t, NULL);
   pthread_join(odd_t, NULL);

   pthread_mutex_destroy(&lock);

   return 0;
}
