#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

//functions in a thread must return a void pointer

void *myturn(void *args) {
	int *v = (int *)args;
	for(int i = 0; i < 10; i++) {
		printf("My Turn: %d * %d = %d\n", i, *v, i * *v);
		sleep(1);
	}

	int *j = mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	*j = *v * 2;
	return (void *)j;
} 

void *yourturn() {
	for(int i = 0; i < 5; i++) {
		printf("Your Turn: %d\n", i);
		sleep(1);
	}
}

int main() {
	pthread_t thread;
	int v = 5;
	void *vv;

	pthread_create(&thread, NULL, myturn, &v);
	yourturn();

	pthread_join(pthread_self(), NULL);
    
}
