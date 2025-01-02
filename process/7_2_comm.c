/**
 * Two way communication between a child and parent process
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int get_pos_int(char *prompt) {
    int num;
    printf("%s", prompt);

    scanf("%i", &num);
    return num;

}

int main() {
    int fd[2], fdb[2];
    /**
     * child process writes to fdb and reads from fd
     * parent process writes to fd and reads from fdb 
     */
    if(pipe(fd) == -1 || pipe(fdb) == -1) {
        printf("Could not create pipe(-1)\n");
        return (-1);
    }
    
    pid_t pid = fork();
    if(pid == 0) {
        close(fd[1]);
        close(fdb[0]);
        int number;
        if(read(fd[0], &number, sizeof(number)) == -1) { return (-3); }
        printf("Reading from the read end of fd pipe");
        number *= 5;


        if(write(fdb[1], &number, sizeof(number)) == -1) { return(-4); }

            close(fd[0]);
        close(fdb[1]);
    }

    else {
        close(fd[0]);
        close(fdb[1]);
        srand(time(NULL));
        int num = rand() % 100;
        if (write(fd[1], &num, sizeof(num)) == -1) return (-2);
        printf("Written %d to file\n", num);
        sleep(.1);

        if(read(fdb[0], &num, sizeof(num)) == -1) return(-5);
        printf("Reading from the read end of fdb pipe");
        printf("Num is %d\n", num);

        close(fd[1]);
        close(fdb[0]);
    }
}