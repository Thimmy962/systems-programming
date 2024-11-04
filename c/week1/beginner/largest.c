#include <stdio.h>

int main() {
    float input;

    for (int i = 0; i < 3; i++) {
        
        if (i == 0){
            printf("Enter a number: ");
            scanf("%f", &input);
        }
        else{
            float temp;
            printf("Enter a number: ");
            scanf("%f", &temp);

            if(temp > input)
            {
                input = temp;
            }
        }
    }
    printf("The largest number is: %.2f\n", input);
}