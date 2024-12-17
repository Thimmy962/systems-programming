#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int id = fork();
	int n;

	if(id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}

	int i;
	for(i = n; i < n+5; i++) {
		printf("%i ", i);
		fflush(stdout);
	}

	if(id == 0) {
		printf("\n");
	}
	return 0;
}
