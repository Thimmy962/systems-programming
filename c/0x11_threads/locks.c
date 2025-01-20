/**
 * a demo into how race condition works
 * since the main and child threads are trying to update the variable COUNTER
 * it becomes a race of which thread updates the variable last wins the race
 * there is a possibility that the threads read the same value
 * this problem can be solved using locks
 * 
 * This program majorly implements thread synchronization using mutex
 * with little focus on synchornization and shared counter 
 */

#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>

#define LARGE 1000000000
uint32_t COUNTER = 0;
// initialize mutex lock
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


void *count() {
    for(uint32_t i = 0; i < LARGE; i++) {
        
        // lock this varibale so no other thread can access the lines below
        pthread_mutex_lock(&lock);
        // pthread_mutex_timedlock(&lock, time_to_wait);  if resource is locked, wait for 2 seconds to see if resource will be unlocked else return
        COUNTER++;
        sleep(1);
        // unlock when done so other threads can access lines above
        pthread_mutex_unlock(&lock);
    }
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, count, NULL);
    count();
    pthread_join(thread, NULL);
    printf("%d\n", COUNTER);
}