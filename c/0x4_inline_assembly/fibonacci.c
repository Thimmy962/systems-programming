#include"func.c"


int main() {
	int  fib_seq = get_int("Enter the number of fib seq: ");

	if(fib_seq == 0 || fib_seq == 1){
		printf("1\n");
		return (0);
	}

	int *fibonacci = malloc(fib_seq);
	if(fibonacci == NULL) return (1);

	fibonacci[0] = 0;
	fibonacci[1] = 1;

	for(int i = 2; i < fib_seq; i++) {
		asm (
			"movl %1, %%eax;" //move the content of variale 1 to eax registry
			"addl %2, %%eax;" // add the content of variable 2 to the eax registry
			"movl %%eax, %0;" // move the content of the eax registry to variable  0
			:"=r" (fibonacci[i])
			:"r" (fibonacci[i - 1]), "r" (fibonacci[i - 2])
			:"eax"
		);
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	for(int i = 0; i < fib_seq; i++) {
		if(i == (fib_seq - 1)) {
			printf("%d\n", fibonacci[i]);
			continue;
		}
		printf("%d, ", fibonacci[i]);
	}

	free(fibonacci);
	exit(0);
}
