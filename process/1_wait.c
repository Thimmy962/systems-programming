#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t id = fork(); // Create a child process
    int n;

    if (id == 0) 
        n = 1; // Child process
    else 
        n = 6; // Parent process

    if (id != 0) {
        int status;
        wait(&status); // Wait for the child process to terminate
    }

    int i;
    for (i = n; i < n + 5; i++) {
        printf("%d ", i);
        fflush(stdout); // Ensure output is printed immediately
    }
    
	if(id == 0 ) {
		printf("\n");
	}

    return 0;
}
