/**
 * child process independent of the child process
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>


/**
 * ctrl-z - sigtsttp
 * ctrl-c - sigint
 */
void handler(int num) {
    printf("\nHello World\n");
}
int main() {
    int x;
    printf("Input number: ");
    scanf("%i", &x);
    printf("Result of %d * 5 is: %d\n", x, x*5);
}