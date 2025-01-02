#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
/**
 * stoping and continuing a process
 * SIGINT - to kill a 
 */

int main() {
    int pid = fork();
    if(pid == -1) {
        return (1);
    }

    if(pid == 0) {
        while(1) {
            write(1, "Hello World\n", 13);
            // sleep for 50ms
            usleep(50000);
        }
    } else {
        sleep(1);
        // kill the process with process id pf pid
        // kill(pid, SIGINT);

        // pause the process
        kill(pid, SIGSTOP);
        // wait for 1s
        sleep(1);
        // continue the process
        kill(pid, SIGCONT);

        wait(NULL);
    }
    return (0);
}