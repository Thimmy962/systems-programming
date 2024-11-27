#include "func.c"

int main(int argc, char **argv) {
    if(argc != 3) {
		printf("Program takes two inputs arguments\n");
		printf("Usage: %s <filename> <logstring>\n", argv[0]);
		exit(1);
	}

    FILE *file = fopen(argv[1], "a");

    if(file == NULL) {
        printf("Could not open file\nExiting programme");
        exit(1);
    }
    fprintf(file, "%s", argv[2]);
    fprintf(file, "\n");

    fclose(file);
    return (0);
}