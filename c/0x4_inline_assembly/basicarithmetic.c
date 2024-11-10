#include "func.c"


float  add(int a, int b) {
	int sum;
	asm (
		"movl %1, %%eax;"
		"addl %2, %%eax;"
		"movl %%eax, %0;"
		:"=r" (sum)
		:"r" (a), "r" (b)
		:"eax"
	);
	return sum;
}

int main() {
	float num1 = get_int("Enter Number: ");
	printf("Choose operand based on number\n1. +\n2. -\n3. /\n4. *\n");
	int operand = get_int("Enter operand: ");
	float num2 = get_int("Enter Number: ");
	float ans = add(num1, num2);
	printf("%.2f\n", ans);
}
