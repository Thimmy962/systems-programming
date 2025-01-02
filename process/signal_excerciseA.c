#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
/**
 * stopping and continuing a process
 * SIGINT - to kill a
 */

int main()
{

    int pid = fork();
    if (pid == -1)
    {
        return (1);
    }

    if (pid == 0)
    {
        while (1)
        {
            write(1, "Hello World\n", 13);
            // sleep for 50ms
            usleep(500000);
        }
    }
    else
    {
        kill(pid, SIGSTOP);
        int t;
        do
        {
            printf("Time in seconds for execution: ");
            scanf("%i", &t);
            kill(pid, SIGSTOP);
            
            if(t > 0) {

                kill(pid, SIGCONT);
                sleep(t);

            }
        } while (t > 0);
        
    }
    return (0);
}