#include "func.c"


void print_2D_arrray(int arr[][5], int rows);
void init_2D_array(int arr[][5], int rows, int cols);

int main() {
    int arr[3][5];
    init_2D_array(arr, 3, 5);

    print_2D_arrray(arr, 3);
    return 0;
}



void print_2D_arrray(int arr[][5], int len) {
    for (int j = 0; j < len; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            printf("%d ", arr[j][i]);
            if(i == 4 && j != len-1)
                printf("\n");
        }
    }
    printf("\n");
}

void init_2D_array(int arr[][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = get_int("Enter element: ");
        }
    }
}