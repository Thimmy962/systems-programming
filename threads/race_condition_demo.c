#include <stdio.h>
#include <pthread.h>
#include <stdint.h>



#define BIG 1000001
uint32_t counter = 0;

void *counter_increment() {
    for(uint32_t i = 0; i < BIG; i++) {
        counter++;
    }
}


int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, counter_increment, NULL);
    counter_increment();
    pthread_join(thread, NULL);

    printf("%d\n", counter);

}