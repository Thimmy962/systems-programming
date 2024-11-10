#include <stdlib.h>
#include <stdio.h>

float add(float op1, float op2){
    return op1 + op2;
}

float sub(float op1, float op2){
    return op1 - op2;
}

float divide(float op1, float op2){
    if (op2 == 0){
        exit(1);
    }
    return op1 / op2;
}

float mul(float op1, float op2){
    return op1 * op2;
}

int main()
{
    float op1, op2, answer;
    char op;
    printf("Enter operand 1: ");
    scanf("%f", &op1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter operand 2: ");
    scanf("%f", &op2);

    switch (op)
    {
        case '-':
            answer = sub(op1, op2);
            printf("%.2f - %.2f = %.2f", op1, op2, answer);
            break;
        case '+':
            answer = add(op1, op2);
            printf("%.2f + %.2f = %.2f", op1, op2, answer);
            break;
        case '/':
            answer = divide(op1, op2);
            printf("%.2f / %.2f = %.2f", op1, op2, answer);
            break;
        case '*':
            answer = mul(op1, op2);
            printf("%.2f * %.2f = %.2f", op1, op2, answer);
            break;
        default:
            break;
    }
    printf("\n");
    exit(0);
}