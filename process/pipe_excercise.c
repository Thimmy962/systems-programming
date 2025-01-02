/**
 * an example of pipe in use
 * where a process sums a half of a list and another sums the other half
 * the second process passes it sum to the first process
 * the first process adds it partial sum to the partial sum of the second process 
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int array[] = {1,2,3,4,5,6,7,8,9,10,11};
    int arrLen = sizeof(array) / sizeof(array[0]);
    int start, end; // where each process should start reading and end reading
    int sum = 0;

    int fd[2]; // arrays need by the pipe
    int pip = pipe(fd);
    if(pip == -1) {
        perror("An error occured");
        return (1);
    }

    pid_t id = fork();
    if(id == -1) {
        return (2);
    }

    if(id == 0) {
        start = 0;
        end = start + (arrLen / 2);
    } else {
        start = (arrLen / 2) + 1;
        end = arrLen - 1;
    }

    for(int i = start; i <= end; i++) {
            sum += array[i];
    }

    if(id == 0) {
        close(fd[0]); //close the read end of the pipe

        // Writing partial sum to pipe
        write(fd[1], &sum, sizeof(int));
        close(fd[1]);
    } else {
        close(fd[1]); // we only reading so close the write end of the pipe
        wait(NULL);

        int y;
        // Reading partial sum from pipe
        read(fd[0], &y, sizeof(sum));
        wait(NULL);
        printf("Sum: %d\n", y + sum);
    }
    return (0);
}