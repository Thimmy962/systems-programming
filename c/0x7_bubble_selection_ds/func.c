#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int get_int(char *prompt)
{

    int num = 0;
    bool valid_input = false;

    while(!valid_input)
    {
        printf("%s", prompt);
        
        char str[15];
        if (fgets(str, 15, stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        bool is_negative = false;
        num = 0;
        valid_input = true;

        int i = 0;
        if (str[0] == '-') {
            is_negative = true;
            i = 1;
        }

        for(; i < 15 && str[i] != '\0' && str[i] != '\n'; i++)
        {
            if(isdigit(str[i]))
            {
                num = num * 10 + (str[i] - '0');   
            }
            else
            {
                printf("Your input is not a valid number. Please try again.\n");
                valid_input = false;
                break;
            }
        }

        if(is_negative)
        {
            num = -num;

        }
    }
    return num;
}

long int get_longint(char *prompt) {
    long int num = 0;
    bool valid_input = false;

    while (!valid_input) {
        printf("%s", prompt);
        
        char str[15];
        if (fgets(str, 15, stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        bool is_negative = false;
        num = 0;
        valid_input = true;

        int i = 0;
        if (str[0] == '-') {
            is_negative = true;
            i = 1;
        }

        for (; i < 15 && str[i] != '\0' && str[i] != '\n'; i++) {
            if (isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
            } else {
                printf("Your input is not a valid number. Please try again.\n");
                valid_input = false;
                break;
            }
        }

        if (is_negative) {
            num = -num;
        }
    }

    return num;
}


char *get_string(char *prompt)
{
    char *str = (char*)malloc(1024);
    if (str == NULL) {
        return NULL;
    }
    printf("%s", prompt);
    fgets(str, 1024, stdin);
    str = realloc(str, strlen(str) - 1);
    str[strlen(str) - 1] = '\0';
    return str;
}

char get_char(char *prompt)
{
    char c;
    printf("%s", prompt);
    scanf("%c", &c);
    return c;
}