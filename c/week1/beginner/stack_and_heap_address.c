/**
 * prints memory location on the stack and heap
 */

#include <stdio.h>
#include <stdlib.h>

void print_heap_memory(int *ptr)
{
    printf("Memory: %p\n", ptr);
}

void print_stack_memory(int *ptr)
{
    printf("Memory: %p\n", ptr);
}

int main()
{
    int a = 10;
    int *ptr = malloc(4);

    print_heap_memory(ptr);
    print_stack_memory(&a);
}