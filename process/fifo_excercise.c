/**
 * using fifo to solve a problem
 */

#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int arr[5];
    srand(time(NULL));
    int i;
    for(i = 0; i < 5; i++) {
        arr[i] = rand() % 100;
    }

    int fd = open("sum", O_WRONLY);
    if(fd == -1 && errno != EEXIST) {
        printf("Could not open file\n");
        return (0);
    }

    int wr = write(fd, arr, sizeof(arr));
    if(wr == -1) {
        printf("Could not write to file");
        return (2);
    }

    close(fd);
    return (0);
}

/**
 * Dows thw same thing as line 27 - 31
    for(i = 0; i < 5; i++) {
        int wr = write(fd, arr, sizeof(arr));
        if(wr == -1) {
            printf("Could not write to file");
            return (2);
        }
        printf("Written %i to file\n", arr[i]);
    }
*/