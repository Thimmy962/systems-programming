/**
 * fifo
 * used to communicate between processes on different heirarchy
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main()
{
    // fifo is a file
    int fifo_status = mkfifo("fifo2", 0777); // name of the fifo file and file permission
    if (fifo_status == -1)
    {
        if (errno != EEXIST) // if the error is not file aready exists
        {
            perror("Could not create file");
            return (1);
        }
    }

    printf("Opening fifo");
    int fd = open("fifo2", O_WRONLY);
    if(fd == -1) {
        perror("Could not open file");
        return (1);
    }
    int age = 20;
    int wr = write(fd, &age, sizeof(age));
    if(wr == -1) {
        printf("There was an error");
    }
    close(fd);

    return (0);
}