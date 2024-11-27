#include "func.c"

int main(int argc, char **argv) {

	if(argc != 3) {
		printf("Program takes two files as arguments\n");
		printf("Usage: %s <input_file> <output_file>\n", argv[0]);
		exit(1);
	}

	char buffer[100];

	char *copy_from = argv[1];
	char *copy_to = argv[2];

	FILE *src_file = fopen(copy_from, "r");

	if(src_file == NULL) {
		printf("Could not open file\n");
		exit(1);
	}

	FILE *dest_file = fopen(copy_to, "w");

	while (fgets(buffer, sizeof(buffer), src_file) != NULL) {
        fprintf(dest_file, "%s", buffer);
    }

	fclose(src_file);
	fclose(dest_file);

	return 0;
}
