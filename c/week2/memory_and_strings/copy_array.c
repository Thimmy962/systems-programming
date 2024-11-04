#include <stdio.h>

void copy_array(int arr1[], int arr2[]) {
    int i = 0;
    while(*(arr1+i)!= '\0')
     {
        *(arr2 + i) = *(arr1 + i);
        i++;
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, arr2[10];

    copy_array(arr1, arr2);



    for(int i = 0; i < 10; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}
