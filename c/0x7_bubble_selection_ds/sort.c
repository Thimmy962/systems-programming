#include <stdio.h>

/**
 * function pointer to sort an array of integers in ascending order
 * algorithms written by me are below in the multiline comment
 * the algorithms written above are optimized version of algorithm i wrote
 * the optimized version was done by chatgpt
 * did a loop benchmark; mine took 500500 loops for the selection sort and 999,000 loops for the bubble sort
 *                                              to sort an array of 1000 ints arranged in descending form to ascending form
 * chatgpt optimization took 499,500 for selection sort and 499500 for bubble sort
 *                                              the array to sort were the same as mine
 *
 */

void print_array(int array[], int size);

void bubble_sort(int arr[], int size)
{
    int count = 0;
    for (int j = size - 1; j >= 0; j--)
    {
        int swap = 0;
        // would have pushed the largest number to the far right, there is no need to check the far right if it is sorted
        for (int i = 1; i <= j; i++)
        {
            count++;

            if (arr[i] < arr[i - 1])
            {
                int temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swap++;
            }
        }
        if (swap == 0)
        {
            break;
        }
    }
    printf("Bubble Sort Counter: %d\n", count);
}

void selection_sort(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        // the value of at inex i is always assumed to be the smallest value
        // the current index
        int smallestValueIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            count++;
            if (arr[j] < arr[i])
            {

                // a new smaller value is found keep track of the index
                smallestValueIndex = j;
            }
        }
        // this
        if (smallestValueIndex != 1)
        {
            int tmp = arr[i];

            // change the value of the current index to the smallest value
            arr[i] = arr[smallestValueIndex];
            // change the value of the index where the smallest value is found to what the smallest value is replacing
            arr[smallestValueIndex] = tmp;
        }
    }
    printf("Selection Sort Counter: %d\n", count);
}

void insertion_sort(int arr[], int size)
{
    int counter = 0;

    for (int i = 1; i < size; i++)
    {
        int swap = 0;
        for (int j = 1; j < size - 1; j++)
        {
            counter++;

            if (arr[j] < arr[j - 1])
            {
                int tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
            }

            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
            swap = 1;
        }
        if (swap == 0)
            break;
    }
    printf("Insertion Counter: %d\n", counter);
}

void (*bubblesort)(int array[], int size) = &bubble_sort;
void (*selectionsort)(int array[], int size) = &selection_sort;

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            printf("%d", array[i]);
            break;
        }
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionsort(arr, n);
    print_array(arr, n);
}

/*
void selection_sort(int arr[], int size)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        // assume the current number is the smallest
        int smallest = arr[i];
        // index on the array where the new smallest value is found
        int smallestValueIndex;
        // a flag set to 0 by default but to 1 if a smaller number than the assumed number is found
        int will_swap = 0;
        for(int j = i; j < size; j++) {
            count++;
            if(arr[j] < smallest)
            {
                // if theere is a smaller number update the variable called smallest
                smallest = arr[j];

                // store the index where the new small nmber is found
                smallestValueIndex = j;

                // set will swap to 1 meaning that we found a smaller number than our assumption
                will_swap = 1;
            }
        }
        // this will be done if a new small value is found
        if(will_swap == 1) {
            int tmp = arr[i];

            // change the value of the current index to the smallest value
            arr[i] = smallest;
            // change the value of the index where the smallest value is found to what the smallest value is replacing
            arr[smallestValueIndex] =  tmp;
        }

    }
    printf("Selection Sort Count: %d\n", count);
}

void bubble_sort(int arr[], int size){
    int count = 0;
    for(int j = size - 1; j>= 0; j--) {
        int swap = 0;
        for(int i = 1; i < size; i++) {
            count++;

            if(arr[i] < arr[i - 1]) {
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                swap++;
            }

        }
        if (swap == 0) {
                break;
            }
    }
    printf("Bubble Sort Count: %d\n", count);
}

*/