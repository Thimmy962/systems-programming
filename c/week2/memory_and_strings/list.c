#include <stdio.h>

int get_int(char *string)
{
    int input;
    printf("%s", string);
    scanf("%i", &input);
    return (input);
}

int main()
{
    int list_size = get_int("How many elements are in your list? ");
    int array[list_size];

    for(int i = 0; i<list_size; i++)
    {
        array[i] = get_int("Enter value: ");

    }

    printf("Array has been initialized");

    for(int i = 0; i<list_size; i++)
    {
        array[i] = get_int("Enter value: ");
    }
    return (0);
}