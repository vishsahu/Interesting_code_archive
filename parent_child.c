/*
 * About:
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

void handler(int num) {
	FILE *ret = NULL;
	ret = fopen("/home/vsahu/work/status_d", "w+");
	if (ret)
		fprintf(ret, "child %d parent %d died, suiciding\n", getpid(), getppid());
	fclose(ret);
	signal(SIGKILL, SIG_DFL);
	return;
}

int main(int argc, char* argv[]) {
	int ret = fork(); // create a child
	if (ret == -1) {
		printf("fork failed\n");
		return -1;
	}
	if (ret == 0) { // child
		int ret = fork(); // create a grand child
		if (ret == -1) {
			printf("fork failed\n");
			return -1;
		}
		if (ret == 0) { // grand child
			if (prctl(PR_SET_PDEATHSIG, SIGUSR1)) {
				printf("Failed to set the death signal for child - %s\n", strerror(errno));
				exit(-1);
			}

			// register handler
			signal(SIGUSR2, handler);

			while (1) {
				printf("child %d is running, parent %d is alive\n", getpid(), getppid());
				sleep(8);
			}
		} else { // parent
			int age = 2;
			while (age-- > 0) {
				printf("parent %d is running\n", getpid());
				sleep(8);
			}
			printf("parent %d is dying now\n", getpid());
			signal(SIGKILL, SIG_DFL);
		}
	} else { // grandparent
		while (1) {
			printf("grand parent %d is running\n", getpid());
			sleep(8);
		}
	}
    return 0;
}
