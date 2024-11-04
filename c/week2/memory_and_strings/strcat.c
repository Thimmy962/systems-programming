/**
 * concatenates two strings
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char *string;

string get_string(char *prompt)
{
    string buffer = malloc(1024);
    if(buffer == NULL){
        return (NULL);
    }
    printf("%s", prompt);
    fgets(buffer, 1024, stdin);
    size_t len = strlen(buffer) + 1;
    buffer = realloc(buffer, len);
    if(buffer == NULL)
    {
        return (NULL);
    }
    return buffer;
}

void strccat(char *dest, char *src) {
    size_t len = strlen(dest) - 1;
    char temp[strlen(dest) + strlen(src) - 1];

    strcpy(temp, dest);

    /**
     * temp is a pointer to a list
     * temp + len: address that is len position away from the beginning of the array address
     */
    // temp + len: the position to start inputting the new string
    // src: the string to input
    strcpy(temp + len, src);
    printf("%s", temp);
}

int main() {
    string name = get_string("First name: ");
    string sname = get_string("Last name: ");

    strccat(name, sname);

    free(name);
    return 0;
}