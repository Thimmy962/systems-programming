/**
 * exec function with fork()
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t id = fork();
    char *cmd[] = {"ls", };
    if(id == 0) {
        int err = execlp("ls", cmd);
        // cant find the program
        if(err == -1) {
            printf("Could not find the programme to execute\n");
            exit(-1);
        }
    }
    else{
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus)) {
            // found the program and executed
            int statuscode = WEXITSTATUS(wstatus);
            // for successful execution, status code is 0
            if(statuscode == 0) {
                printf("Sucess with status code \n");
            }
            //  for failed execution
            else {
                printf("Failed with error code: %d\n", statuscode);
            }
        }
    }
}