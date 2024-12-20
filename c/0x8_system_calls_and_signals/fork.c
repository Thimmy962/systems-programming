/**
 * forks a process and print the process ID
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int id = fork();
	int n;

	if(id == 0) {
		printf("Child process with id of: %d\n", getpid());
	}
	else {
			printf("Parent process with id of: %d\n", getpid());
		wait(&n);
	}
	return 0;
}
