#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int id  = fork();
	if(id == 0)
		printf("Hello World child process\n");
	else
		printf("Hello World parent process\n");
	return (0);
}
