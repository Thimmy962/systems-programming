/**
 * compares 2 strings
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef char *string;

bool compare_string(string string_1, string string_2)
{
    if(strlen(string_1) != strlen(string_2))
    {
        return (false);
    }

    for(int i = 0; string_1[i] != '\0' && string_2[i] != '\0'; i++)
    {
        if(string_1[i] != string_2[i]){
            return (false);
        }
    }

    return (true);
}




int main(void){
    string name[10];
    string sname[10];
    printf("Enter first name: ");
    scanf("%s", name);

    printf("Enter first name: ");
    scanf("%s", sname);
    bool str = compare_string(name, sname);
    if(str == 1)
    {
        printf("They are the same\n");
        return (0);
    }
        printf("They are not the same\n");
        return (0);

}