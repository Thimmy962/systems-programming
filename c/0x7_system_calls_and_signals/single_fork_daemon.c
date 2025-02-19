/**
 * daemon process using the single fork method
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/**
 * main - ebtry point
 * return: 0 for success and others for error
 */
int main() {
    umask(0);
    pid_t pid = fork();

    if(pid == -1) 
        _Exit(EXIT_FAILURE);
    /**
     * this child process is working as a daemon
     */
    else if (pid > 0) {
        exit(0);
    }

    setsid();

    if(chdir("/home/thimmy/") < 0) {
        perror("Could not change directory");
    }



    int fd = open("hello.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
    char *name = "My name is Timileyin\n";
    if(fd == -1) {
        int err = open("/var/log/daemon.log", O_APPEND);
        char *mes = "Could not open hello.txt file in the home directory\n";
        write(err, mes, strlen(mes));
        close(err);
        _Exit(EXIT_FAILURE);
    }

    /**
     * tested by closing all file descriptors when the daemon works well
     * this way any problem the daemon encounters before running can be printed to terminal
    */
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);



    while(1) {
        sleep(5);
        write(fd, name, strlen(name));
    }
    close(fd);
}
