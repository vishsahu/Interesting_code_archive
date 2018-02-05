/*
 * About:
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>

int main(int argc, char* argv[]) {
	int fd = open("/ifs/data/foo.txt", O_RDWR | O_CREAT | O_TRUNC);
	if (fd == -1) {
		printf("File open failed - %s", strerror(errno));
		return -1;
	}
    	int ret = -1, q;
	q = kqueue();
    	if (q == -1) {
		printf("kqueue failed - %s\n", strerror(errno));
		return -1;
	}

	struct kevent check = {};
	struct kevent found = {};

	/* add event to monitor different things happening to a file */
	intptr_t data;
	void *udata = NULL;
	EV_SET(&check, fd, EVFILT_VNODE, EV_ADD | EV_CLEAR, NOTE_ATTRIB | NOTE_DELETE | NOTE_WRITE | NOTE_RENAME | NOTE_LINK, data, udata);
	ret = kevent(q, &check, 1, NULL, 0, NULL); // add to queue
	if (ret == -1) {
		printf("Failed to add event to queue for tracking - %s\n", strerror(errno));
		return -1;
	}
	while (1) { // loop
		ret = kevent(q, &check, 1, &found, 1, NULL);
		if (ret == -1) {
			printf("Failed to process event from queue - %s\n", strerror(errno));
			return -1;
		}
		else if (ret > 0)
			printf("event occured, continuing\n");
	}
	if (fd > 0)
		close(fd);
    return 0;
}
