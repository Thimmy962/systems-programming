/**
 * prints the hexadecimal representation of the values of a string
 */


#include <stdio.h>
#include <string.h>

int main() {

    char *name = "Thimmy";

    for(int i = 0; i < strlen(name); i++)
    {
        printf("%x ", name[i]);
    }
    printf("\n");
}