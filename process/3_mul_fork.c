#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int ida = fork();
    int idb = fork();
    if (ida == 0)
        printf("Parent pid of process %d  is: %d\n", getpid(), getppid());
    else
        printf("Parent pid is: %d\n", getpid());
}