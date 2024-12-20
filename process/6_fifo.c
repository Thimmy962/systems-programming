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
    int fifo_status = mkfifo("fifo", 777); // name of the fifo file and file permission
    if (fifo_status == -1)
    {
        if (errno != EEXIST) // if the error is not file aready exists
        {
            perror("Could not create file");
            return (1);
        }
    }

    int fd = open("fifo", O_WRONLY);
    if(fd == -1) {
        perror("Could not open file");
        return (1);
    }
    int age;
    write(fd, &age, sizeof(age));
    close(fd);

    return (0);
}