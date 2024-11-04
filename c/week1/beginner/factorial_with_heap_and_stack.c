/**
 * prints the factorial of a given number using heap and stack
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * heap_factorial - calculates the factorial of a given number using heap
 * @n: the number to calculate the factorial for
 * return: the factorial of the given number
 */
long int heap_factorial(int n) {
    if (n == 0 || n == 1){
        return (1);
    }

    long int *heap = malloc(n * sizeof(long int));
    *heap = 1;
    for (int i = 2; i <= n; i++) {
        *heap *= i;
    }

    int num = *heap;
    free(heap);
    return num;

}

/**
 * stack_factorial - calculates the factorial of a given number using stack
 * @n: the number to calculate the factorial for
 * return: the factorial of the given number
 */
long int stack_factorial(int n) {
    if (n == 0 || n == 1) {
        return (1);
    }

    return (n * stack_factorial(n-1));
}

/**
 * get_int - gets an integer from the user
 * @string: the prompt to display to the user
 * return: the integer entered by the user
 */
int get_int(char *string)
{
    int input;
    printf("%s", string);
    scanf("%i", &input);
    return (input);
}

/**
 * main - the entry point of the program
 * return: 0 on success, 1 on failure
 */
int main(void) {
    int n = get_int("Enter a number: ");

    printf("Factorial of %i using heap: %li\n", n, heap_factorial(n));
    printf("Factorial of %i using stack: %li\n", n, stack_factorial(n));

    return (0);
}