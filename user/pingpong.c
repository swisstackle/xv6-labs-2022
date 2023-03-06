#include "kernel/types.h"
#include "user/user.h"

int main() {
	int fd[2];
	int fd2[2];
	pipe(fd);
	pipe(fd2);
	char byte = 'c';
	int pid = fork();
	if(pid == 0) {
		char received;
		close(fd[1]);
		read(fd[0], &received, 1);
		printf("%d: received ping\n", getpid());
		close(fd2[0]);
		write(fd2[1], &received, 1);
		close(fd2[1]);
		exit(0);
	} else {
		close(fd[0]);
		write(fd[1], &byte, 1);
		char receivedFromChild;
		read(fd2[0], &receivedFromChild, 1);
		printf("%d: received pong\n", getpid());
		exit(0);
	}
	wait(0);
}
