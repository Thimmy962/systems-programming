#include "func.c"

int main(int argc, char **argv) {
	if(argc == 1) {
		printf("File name not given\n");
		exit(1);
	}

	char *file = argv[1];

	FILE *file_ptr = (file, "w");
}
