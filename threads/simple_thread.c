#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//functions in a thread must return a void pointer
void *myturn() {
	for(int i = 0; i < 10; i++) {
		printf("My Turn: %d\n", i);
		sleep(1);
	}
	return NULL;
} 

void yourturn() {
	for(int i = 0; i < 5; i++) {
		printf("Your Turn: %d\n", i);
		sleep(1);
	}
}

int main() {
	pthread_t thread;
	pthread_create(&thread, NULL, myturn, NULL);
	yourturn();

	pthread_join(thread, NULL);

}
