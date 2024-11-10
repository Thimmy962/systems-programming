#include "func.c"
/**
*Test bitwise operators
*/


int andbit() {
    int i = get_int("Enter first number: ");
    int j = get_int("Enter second number: ");
    return i & j;

}

int orbit() {
    int i = get_int("Enter first number: ");
    int j = get_int("Enter second number: ");
    return i | j;;
}

int xorbit() {
    int i = get_int("Enter first number: ");
    int j = get_int("Enter second number: ");
    return i ^ j;
}

int notbit() {
    int i = get_int("Enter number: ");
    int result = ~i;
    return result;
}

int leftshift_2() {
    int i = get_int("Enter number: ");
    return i << 2;
}

int rightshift_2() {
    int i = get_int("Enter number: ");
    return i >> 2;
}



int main() {
    int num1 = get_int("Enter first number: ");
    int num2 = get_int("Enter second number: ");

    printf("First Num is: %d\ and Second Num is: %d\n", num1, num2);

    bitswap(&num1, &num2);

    printf("First Num is: %d\ and Second Num is: %d\n", num1, num2);
}
