#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if(argc < 3) {
        char *error = "Usage: programe <number of data block> <size of data block>\n";
        write(2, error, strlen(error));
        exit(1);
    }

    int num_of_blocks = atoi(argv[1]);
    int blocks_size = atoi(argv[2]);


    int fd1[2];
    pipe(fd1);

    pid_t pid = fork();

    // child process
    if(pid == 0) {
        close(fd1[0]); // close read end

        char *size = malloc(blocks_size);

        for (int i = 0; i < num_of_blocks; i++) {
            memset(size, 'A', blocks_size);
            int fd = write(fd1[1], size, blocks_size);
           if(fd == -1) {
                perror("Could not write to pipe");
                exit(2);
            }   
        }
        free(size);  // Clean up memory
        close(fd1[1]);
    } 
    else {
        wait(NULL);
        struct timeval start, end;
        close(fd1[1]); // close read end
        char *buffer = malloc(blocks_size);  // Allocate space to receive the block

        gettimeofday(&start, NULL);
        for (int i = 0; i < num_of_blocks; i++) {
            int fd = read(fd1[0], buffer, blocks_size);   // Read the block
        }
        gettimeofday(&end, NULL);

        // time elapsed in seconds
        float time = ((float)end.tv_usec - (float)start.tv_usec) / 1000;
        float mem_size = (blocks_size * num_of_blocks) / 1024;

        printf("Time elapsed: %.2fs\nMemory Size: %fkb\nBandwidth: %.2fkb/s\n", time, mem_size, mem_size/time);

        free(buffer);  // Clean up memory
        close(fd1[0]);
    }

}
