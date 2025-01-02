/**
 * daemon process using the single fork method
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>



/**
 * daemon - a daemon process
 * @flags: flags required
 * return: 0 for success and < 0 for any kind of error
 */
int daemonize(int flags)
{   
    umask(0);
    // int log = open("/var/log/damon.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
    // if(log == -1) {
    //     _Exit(1);
    // }
    pid_t pid = fork();

    if (pid == -1)
        _Exit(2);

     // exit the parent process
    if (pid > 0)
    {
        _Exit(EXIT_SUCCESS);
    }

    

    // call setsid with no argument to detach from the current terminal session and create a new session that is not associated with a controlling terminal.
    // setid - set session ID
    setsid();

    // change current work dir to root
    if(chdir("/home/thimmy/") < 0) {
        perror("Could not change directory");
    }

    /**
     * close all file descriptors
     * fd ranges from 0: standard input to as high as 1024
     * closing everyone of them requires a loop that targets each fd number.
     */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int log_fd = open("/var/log/daemon.log", O_CREAT | O_WRONLY | O_APPEND, 0666);
    if (log_fd == -1) {
        dup2(log_fd, STDERR_FILENO); // Redirect only stderr to a log file
    }
    
    char *daemon = "Daemon start\n";
    write(log_fd, daemon, strlen(daemon));
    
    
    close(log_fd);

    return 0;
}

/**
 * main - entry point
 * return: 0 for success and others for error
 */
int main()
{
    
    char *greet = "Hi\n";
    switch(daemonize(1)) {
        case 0: {
            printf("Successful\n");
        }
        default: {
            printf("Failed\n");
        }
   }
    
    int fd = open("hello.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
   while(1) {
        sleep(60);
        if(write(fd, greet, strlen(greet)) == -1) {
            perror("Could not write to file\n");
        }
   }
    close(fd);
}
