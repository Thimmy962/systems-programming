#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
    printf("MAIN ID: %d\n", getpid());
    int ida = fork(); // main process is forked into 2 processes
    /**
     * p1 and p2
     * main process is p1 and child process p2
     */
    int idb = fork();
    /**
     * fork is called again
     * p1 produces: p1 and a child process
     * p2 produces: p2 and a child process which is like a grand child to p1
     */
    int idc = fork();

    if(ida != 0 && idb != 0) {
        printf("Main process ID is: %d\n", getpid());
    }
    if (ida == 0)
    {
        if(idb == 0) {
            printf("Grand child parent ID is: %d\n", getppid());
        }
        else{
            printf("First child ID is: %d\n", getpid());
        }
    }
    else if(idb == 0){
        printf("Second child ID is: %d\n", getppid());
    }
    /**
     * while waiting for a child or while a child process is still running
     */
    while(wait(NULL) != -1 || errno != ECHILD) {
        printf("Waited for a child to finish\n");
    }
}