/**
 * using fifo to solve a problem
 */

#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int arr[5];
    int fd = open("sum", O_RDONLY);
    if(fd == -1) {
        printf("Could not open file\n");
        return (2);
    }

    int i, sum = 0;


    for(i = 0; i < 5; i++) {
        read(fd, &arr[i], sizeof(arr));
        printf("Read %i from file\n", arr[i]);
        sum += arr[i];
    }

    close(fd);

    printf("Sum of read numbers is: ");
    printf("%i\n", sum);;
    return (0);
}
