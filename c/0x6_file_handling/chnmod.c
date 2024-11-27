#include "func.c"

int main(int argc, char **argv) {

	if(argc != 3) {
		printf("Program takes two input as arguments\n");
		printf("Usage: %s <input_file> <new_mode>\n", argv[0]);
		exit(1);
	}

    char *file_name = argv[1];
    char *new_mode = argv[2];

	chmod(file_name, new_mode);

	return 0;
}

