/**
 * reverses an array
 */

#include <stdio.h>

void func_array(int array[], int size)
{
    // divide the string into two
    int mid = size / 2;

    // the last value of the array is always indexed at size - 1
    int last = size - 1;

    for(int i = 0; i < mid; i++)
    {
        int a = *(array+i);
        *(array+i) = *(array + last - i);
        *(array + last - i) = a;
        // printf("%i ", *(array + i));
        // printf("%i ", *(array + last - i));
    }
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    func_array(array, sizeof(array)/sizeof(array[0]));
    for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}