#include "func.c"

typedef struct node {
	char word[20];
	struct node *next;
}node;

void free_array(node *array) {
        node *ptr = array;
        while(ptr != NULL) {
                array = ptr->next;
                free(ptr);
                ptr = array;
        }
}

void print_array(node *array) {
	printf("\n");
	printf("\n");
	printf("Heap Memory Layout\n");
	for(int i = 0; i < 10; i++) {
		printf("__");
	}
	printf("\n");
	printf("\n");

	printf("Address\t\t| Value\n");
	for(int i = 0; i < 10; i++) {
		printf("__");
	}

	printf("\n");

	for(node *ptr = array->next; ptr != NULL; ptr = ptr->next) {
		// Let array be pointing to the next node.
		printf("%p\t| %s\n", ptr, ptr->word);
	}
}

int main() {
	int array_len = get_int("Enter array length: ");
	if(array_len < 1) {
		printf("Length can`t be less than 1\n");
		exit(1);
	}
	node *array = malloc(sizeof(node));
	if(array == NULL){
		exit(1);
	}
	// this is for appennding to the array.
	array->next = NULL;
	// ptrr should always be set to the last node of the array.
	node *ptrr = array;
	for(int i = 0; i < array_len; i++) {
		// new node called ptr.
		node *ptr = malloc(sizeof(node));
		if(ptr == NULL) {
			free(array);
		}

		printf("Enter word: ");
		// // read the word from the user.
		scanf("%s", ptr->word);
		// set the next pointer of ptr to NULL.
		ptr->next = NULL;
		// set the next pointer of ptrr to ptr.
		ptrr->next = ptr;
		// set the ptrr to ptr because ptr is the last node of the array.
		ptrr = ptr;
	}
	print_array(array);
	free_array(array);
	return (0);
}
