/*
 * About:
 */
#include <stdio.h>
#include <pthread.h>
#include <string.h>

int count = 20;
pthread_mutex_t lock;
pthread_cond_t a2b, b2a;

void* A(void *x) {
	while (1) {
		pthread_mutex_lock(&lock);
		if (count % 2) // wait at odd
			pthread_cond_wait(&b2a, &lock);
		count--; // make odd even
		pthread_mutex_unlock(&lock);
		printf("thread A %2d\n", count);
		pthread_cond_signal(&a2b);
		if (count <= 0)
			break;
	}
	return NULL;
}

void* B(void *x) {
	while (1) {
		pthread_mutex_lock(&lock);
		if (count % 2 == 0) // wait at even
			pthread_cond_wait(&a2b, &lock);
		count--; // make even odd
		pthread_mutex_unlock(&lock);
		printf("thread B %2d\n", count);
		pthread_cond_signal(&b2a);
		if (count <= 0)
			break;
	}
	return NULL;
}

int main(int argc, char* argv[]) {
	pthread_t ta, tb;
	int ret = 0;

	ret = pthread_mutex_init(&lock, NULL);
	if (ret) {
		printf("Could not initialize the lock - %s\n", strerror(ret));
		return -1;
	}

	ret = pthread_cond_init(&a2b, NULL);
	if (ret) {
		printf("a2b ptrhread cond init failed - %s\n", strerror(ret));
		return -1;
	}

	ret = pthread_cond_init(&b2a, NULL);
	if (ret) {
		printf("b2a ptrhread cond init failed - %s\n", strerror(ret));
		return -1;
	}

	ret = pthread_create(&ta, NULL, A, NULL);
	if (ret) {
		printf("Could not create thread A - %s\n", strerror(ret));
		return -1;
	}

	ret = pthread_create(&tb, NULL, B, NULL);
	if (ret) {
		printf("Could not create thread B - %s\n", strerror(ret));
		return -1;
	}

	pthread_join(ta, NULL);
	pthread_join(tb, NULL);

    return 0;
}
