/**
 * shares messages or data between process
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>


/**
 * pipe takes in an array of 2 ints
 */
int main() {
    int fd[2];
    int pp = pipe(fd);

    /**
     * fd[0] - where to read from
     * fd[1] - where to write to
     */

    if(pp == -1) {
        printf("An error occured with opening the pipe");
        return (1);
    }

    pid_t id = fork();
    if(id == -1) {
        perror("Could not create a new process\n");
        return (1);
    }
    if(id != 0) {
        wait(NULL);
    }
    if(id == 0) {
        close(fd[0]);
        int i;
        printf("Enter a number: ");
        scanf("%d", &i);
        int write_to_pipe = write(fd[1], &i, sizeof(int));
        if(write_to_pipe == -1) {
            perror("An error occured while sending message from the child process");
            return 1;
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));
        printf("Age is %d\n", y);
        close(fd[0]);
    }

    return (0);
}