/**
 * reverses a string
 */

#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {

    int str_len = strlen(str);
    char temp;

    for (int i = 0; i < str_len / 2; i++) {
        temp = str[i];
        str[i] = *(str + str_len - i - 1);
        *(str + str_len - i - 1) = temp;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverse_string(str);
    printf("Reversed string: %s\n", str);
    return 0;
}