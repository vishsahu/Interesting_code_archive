/*
 * About:
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>

const char *sh = "/shm";
const char *lock_file = "/home/vsahu/lfile";
const char *text = "Written by vishal sahu";
const char *text1 = "Modified by vishal sahu";

#define MEM_SIZE 4096

int main(int argc, char* argv[]) {
	void *retc = NULL;
	int ret = -1, shm_fd = -1;

	shm_fd = shm_open(sh, O_RDWR | O_CREAT, 777);
	if (shm_fd < 0) {
		printf( "Failed to open shared memory - %s",
		        strerror(errno));
		ret = -1;
		goto out;
	}

	printf("fd in parent is %d\n", shm_fd);

	retc = mmap(0, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (retc == MAP_FAILED) {
		printf("parent Map failed %s", strerror(errno));
		ret = -1;
		goto out;
	}

	bzero(retc, MEM_SIZE);	
	memcpy(retc, text, strlen(text));

	ret = msync(retc, MEM_SIZE, MS_SYNC);
	if (ret == -1) {
		printf("Failed to write shared memory - %s",
		        strerror(errno));
		goto out;
	}

	
	int pid = fork();
	if (pid > 0) {
		char g[MEM_SIZE];
child_reread:
		printf("Reading shm in child:\n");
		shm_fd = shm_open(sh, O_RDWR | O_CREAT, S_IRWXO | S_IRWXG | S_IRWXU);
		if (shm_fd < 0) {
			printf( "Child failed to open shared memory - %s",
			        strerror(errno));
			ret = -1;
			goto out;
		}

		printf("fd in child is %d\n", shm_fd);

		retc = mmap(0, MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
		if (retc == MAP_FAILED) {
			printf("child Map failed %s", strerror(errno));
			ret = -1;
			goto out;
		}

		memcpy(g, retc, MEM_SIZE);
		printf("Read in child - %s\n", g);

		ret = munmap(retc, MEM_SIZE);
		if (ret == -1) {
			printf("Failed to unmap shared memory - %s",
			        strerror(errno));
			goto out;
		}

		sleep(10);

		printf("Reading again in child\n");
		goto child_reread;
		
	} else if (pid == 0) {
		sleep(5);
		bzero(retc, MEM_SIZE);
		memcpy(retc, text1, strlen(text1));
		
		ret = msync(retc, MEM_SIZE, MS_SYNC);
		if (ret == -1) {
			printf("Failed to modify shared memory - %s",
			        strerror(errno));
			goto out;
		}
	}
	
	ret = munmap(retc, MEM_SIZE);
	if (ret == -1) {
		printf("Failed to unmap shared memory - %s",
		        strerror(errno));
		goto out;
	}
out:
	shm_unlink(sh);
	return ret;

}
