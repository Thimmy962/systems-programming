#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

/**
 * shell program using exec function
 */

int num_of_words(char *cmd);
void tokenize(char *cmd, char **tokens);
void strip_whitespace(char *str);
void my_exec(char **);
void cleanup();
int comp(char *, char *);

void sigint_handle(int num) {
    fflush(stdout);
    write(0, "Hello World\n", 12);
}



int main()
{
    signal(SIGINT, sigint_handle);
    char *tokens[10];

    while (1)
    {
        printf("$ ");
        char *input;
        fgets(input, 100, stdin);

        // clean up the 
        input[strcspn(input, "\n")] = '\0';

        // // strip white space
        // strip_whitespace(input);
        if(comp(input, "exit") == 0) {
            return (0);
        }
        

        int word_len = num_of_words(input);
        // break the input into an array of strings

        tokenize(input, tokens);
        
        pid_t id = fork();

        if(id == 0) {
            my_exec(tokens);
        } else{
            cleanup();
            for (int j = 0; j < word_len; j++) {
                free(tokens[j]); // Free allocated memory
            }
        }

    }
}

void my_exec(char **tokens)
{
    int err = execvp(tokens[0], tokens);
    if(err == -1) {
        printf("%s: Command not found\n", tokens[0]);
        return;
    }
}

void cleanup() {
    int statcode;
    wait(&statcode);
    if(WIFEXITED(statcode)) {
            //  for failed execution
        if(statcode != 0) {
            printf("Failed with error code: %d\n", statcode);
        }
    }

}

void tokenize(char *cmd, char **tokens) {
    char *delim = " ";
    int i = 0;
    char *token = strtok(cmd, delim);
    while (token != NULL) {
        tokens[i] = malloc(strlen(token) + 1); // Allocate memory for the token
        strcpy(tokens[i], token);             // Copy token into the array
        i++;
        token = strtok(NULL, delim);          // Get the next token
    }
    tokens[i] = NULL;

}



int num_of_words(char *cmd)
{
    int word_len = 0;
    int str_len = strlen(cmd);

    /**
     * strlen also counts in '\0' as a char
     * if user presses enter alone without typing an input, that is a word with one char called \0
     * to account for this, the len of word should be at least 2 in len
     */
    if (str_len < 2)
    {
        return 0;
    }

    int i = 0;
    // Skip leading spaces
    while (i < str_len && cmd[i] == ' ')
    {
        i++;
    }

    int last_space = 0;
    for (; i < str_len; i++)
    {
        if (cmd[i] == ' ')
        {
            word_len++;
        }
    }
    return word_len += 1;
}


void strip_whitespace(char *str) {
    // Trim leading whitespace
    char *start = str;
    while (*start == ' ') {
        start++;
    }

    // Trim trailing whitespace
    char *end = start + strlen(start) - 1;
    while (end > start && *end == ' ') {
        *end = '\0';
        end--;
    }

    // Move trimmed string to the start of the buffer
    if (start != str) {
        memmove(str, start, strlen(start) + 1); // +1 to include the null terminator
    }
}


int comp(char *s1, char *s2) {
    while(*s1 != '\0' || *s2 != '\0') {
        if(*s1 != *s2) return (-1);
        s1++;
        s2++;
    }
    return 0;
}