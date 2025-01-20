#include <stdio.h>
#include <pthread.h>
#include <sys/mman.h>

void *producer_func() {
    char *name = mmap(NULL, 50, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    printf("What is your name: ");
    scanf("%s", name);
    return name;
}

void *consumer_func(void *name) {
    printf("%s\n", (char *)name);
}

int main() {
    pthread_t producer, consumer;
    pthread_create(&producer, NULL, producer_func, NULL);
    void *name;
    pthread_join(producer, &name);

    pthread_create(&consumer, NULL, consumer_func, name);
    pthread_join(consumer, NULL);

}

