/**
 * The code in comment is what I wrote
 * The code below is whats chatGPT modified my code into to make it use one pipe instead of 2
 */

// /**
//  * an example of pipe in use
//  * where a process sums a half of a list and another sums the other half
//  * the second process passes it sum to the first process
//  * the first process adds it partial sum to the partial sum of the second process
//  */
// #include <stdio.h>
// #include <unistd.h>
// #include <sys/wait.h>
// #include <errno.h>

// int main() {
//     int array[] = {1,2,3,4,5,6,7,8,9,10,11};
//     int arrLen = sizeof(array) / sizeof(array[0]);
//     int start, end; // where each process should start reading and end reading
//     int sum = 0;

//     int fd[2], fdb[2]; // arrays need by the pipe
//     int pip = pipe(fd);
//     int pipb = pipe(fdb);
//     if(pip == -1 || pipb == -1) {
//         perror("An error occured");
//         return (1);
//     }

//     pid_t id = fork();
//     pid_t newID;
//     if(id == -1) {
//         return (2);
//     }

//     if(id == 0) {
//         start = 0;
//         end = start + (arrLen / 2);
//     } else {
//         newID = fork();
//         if(newID == -1){
//             perror("Error in creating process");
//             return 2;
//         }
//         start = (arrLen / 2) + 1;
//         end = arrLen - 1;
//     }

//     // first child writing to pipe
//     if(id == 0){
//         for(int i = start; i <= end; i++) {
//             sum += array[i];
//         }
//         printf("Child 1: %d\n", sum);
//         close(fd[0]); //close the read end of the pipe

//         // Writing partial sum to pipe
//         write(fd[1], &sum, sizeof(int));
//         close(fd[1]);
//     }

//     // second child writing to pipe
//     if(id != 0 && newID == 0){
//         for(int i = start; i <= end; i++) {
//             sum += array[i];
//         }
//         printf("Child 2: %d\n", sum);
//         close(fdb[0]); //close the read end of the pipe

//         // Writing partial sum to pipe
//         write(fdb[1], &sum, sizeof(int));
//         close(fdb[1]);
//     }

//     if(id != 0) {
//         if(newID != 0) {
//             wait(NULL);
//             //close the write end for both pipes
//             close(fd[1]);
//             close(fdb[1]);

//             int partialSum1, partialSum2;
//             read(fd[0], &partialSum1, sizeof(int)); // Read first child's sum
//             read(fdb[0], &partialSum2, sizeof(int));

//             printf("Sum: %d\n", partialSum1 + partialSum2);
//         }
//     }

//     return (0);
// }

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int arrLen = sizeof(array) / sizeof(array[0]);
    int start, end;
    int sum = 0;

    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t id = fork();
    if (id == -1)
    {
        perror("Fork failed");
        return 2;
    }

    pid_t newID = -1;
    if (id > 0)
    { // Only parent forks again
        newID = fork();
        if (newID == -1)
        {
            perror("Fork failed");
            return 3;
        }
    }

    // First child process
    if (id == 0)
    {
        start = 0;
        end = arrLen / 2;
        for (int i = start; i <= end; i++)
        {
            sum += array[i];
        }
        close(fd[0]);                    // Close read end
        write(fd[1], &sum, sizeof(int)); // Write partial sum to pipe
        close(fd[1]);
        return 0;
    }

    // Second child process
    if (newID == 0)
    {
        start = (arrLen / 2) + 1;
        end = arrLen - 1;
        for (int i = start; i <= end; i++)
        {
            sum += array[i];
        }
        close(fd[0]);                    // Close read end
        write(fd[1], &sum, sizeof(int)); // Write partial sum to pipe
        close(fd[1]);
        return 0;
    }

    // Parent process
    if (id > 0 && newID > 0)
    {
        close(fd[1]); // Close write end

        int partialSum1, partialSum2;
        // keep waiting as long as there is a child process
        while (wait(NULL) > 0)
        {
            wait(NULL);
        }

        read(fd[0], &partialSum1, sizeof(int)); // Read first partial sum
        read(fd[0], &partialSum2, sizeof(int)); // Read second partial sum
        close(fd[0]);                           // Close read end

        printf("Sum: %d\n", partialSum1 + partialSum2);
    }

    return 0;
}
