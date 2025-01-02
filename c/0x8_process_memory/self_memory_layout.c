/**
 * printing out the memory segments
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

char *program_name(char *);

int main(int argc, char *argv[]) {
    char *programme_name = program_name(argv[0]);
    printf("%s\n", programme_name);


    FILE *file = fopen("/proc/self/status", "r");

    if(!file) {
	perror("Could not open file\n");
	_Exit(EXIT_FAILURE);
    }
    char line[256];
	while(fgets(line, sizeof(line), file)) {
		if(strstr(line, "VmSize") != NULL || strstr(line, "VmRss") != NULL 
            || strstr(line, "VmData") != NULL || strstr(line, "VmStk") != NULL || strstr(line, "VmExe") != NULL
            ||  strstr(line, "VmLib") != NULL || strstr(line, "Threads") != NULL || strstr(line, "State") != NULL) {
            printf("%s", line);
        }
	}
    fclose(file);
    return 0;
}

/**
 * program_name - Returns the program name without the ./
 * @string: the string to be manipulated
 * Return: Pointer to the new string
 */
char *program_name(char *string) {
    // Check if "./" exists in the string
    if (strstr(string, "./") == NULL)
        return string;

    // Calculate the length for the new string (excluding "./" and including '\0')
    int len = strlen(string) - 2 + 1;

    // Allocate memory using mmap
    char *prog_name = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (prog_name == MAP_FAILED) {
        perror("mmap failed");
        return NULL;
    }

    // Copy from the 3rd character onward
    strcpy(prog_name, string + 2);

    return prog_name;
}