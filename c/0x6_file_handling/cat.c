#include "func.c"


void print_file(FILE *file, char *file_name) {
	printf("Reading file %s\n", file_name);
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
	printf("\n");
}


void read_file(char *file_name) {
	FILE *file = fopen(file_name, "r");
	if (file == NULL) {
		printf("Error: Could not open file %s\n", file_name);
		exit(1);
	}
	printf("Contents of %s:\n", file_name);
	print_file(file, file_name);
	fclose(file);
}

int main(int argc, char **argv) {

	if(argc < 2) {
		printf("Program takes file(s) as arguments\n");
		printf("Usage: %s filename(s)", argv[0]);
		exit(1);
	}

	for(int i = 1; i < argc; i++) {
		read_file(argv[i]);
	}
	return 0;
}
