/*
 * Program to print the address of a recursive function variable
*/

#include <stdio.h>

int print_address(int *value)
{
    printf("Address of ptr: %p\n", &value);
    if (value == 0){
        return (1);
    }
    return (print_address(value - 1));
}

int main()
{
    int a = 10;
    print_address(&a);
    return (0);
}