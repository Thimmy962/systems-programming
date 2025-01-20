/**
 * a demo into how race condition works
 * since the main and child threads are trying to update the variable COUNTER
 * it becomes a race of which thread updates the variable last wins the race
 * there is a possibility that the threads read the same value
 * this problem can be solved using locks in another program
 * 
 * This program implements shared counter and race condition
 */

#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

#define BIG 100000000
uint32_t COUNTER = 0;

void *counter_increment()
{
    for (uint32_t i = 0; i < BIG; i++)
    {
        COUNTER++;
    }
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, counter_increment, NULL);
    counter_increment();
    pthread_join(thread, NULL);

    printf("%d\n", COUNTER);
}