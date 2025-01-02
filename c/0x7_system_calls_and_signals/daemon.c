/**
 * making a daemon process using daemon function
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // change to home dir
    int nochir = 0;

    //
    int noclose = 0;

    if(daemon(nochir, noclose))
        perror("Daemon");

    sleep(300);
    return (0);
}