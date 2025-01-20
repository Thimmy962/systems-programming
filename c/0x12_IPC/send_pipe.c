#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    if(pipe(fd) == -1) {
        perror("Pipe cold not be created\n");
        exit(1);
    }
    pid_t pid = fork();
    if(pid == 0) {
       close(fd[0]); // close read end

       int num;
       printf("Enter number here: ");
       scanf("%d", &num);
       int wr = write(fd[1], &num, sizeof(num));
        if(wr == -1) {
            perror("Could not write to buffer\n");
            exit(1);
        }
        close(fd[1]);
    } else {
        wait(NULL);
        close(fd[1]); // close write end
        int num;
        int rd = read(fd[0], &num, sizeof(num));
        if(rd == -1) {
            perror("Could not read from file\n");
            exit(1);
        }

        printf("%d\n", num);
    }
}
