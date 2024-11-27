#include "func.c"

/**
 * Function to print a 2D array
 */


void print_arrray(int arr[][4], int len) {
    for (int j = 0; j < len; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", arr[j][i]);
            if(i == 3 && j != len-1)
                printf("\n");
        }
    }
    printf("\n");
}


int main() {
    int arr[][4] = {{1,2,3, 4}, {5,6,7,8}, {9,10,11,12}};
    print_arrray(arr, 3);
    // print_arrray(arr, 10);
    return 0;
}