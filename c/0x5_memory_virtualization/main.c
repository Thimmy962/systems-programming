#include "func.c"


typedef char *string;
typedef struct node {
	string word;
	struct node *next;
}node;

void free_array(node *array) {
	node *ptr = array;
	while(ptr != NULL) {
		//let array be poiting to the next node. This detach the first node from the rest and saves its address in ptr
		array = ptr->next;
		free(ptr->word);
		free(ptr);
		ptr = array;
	}
}

void print_array(node *array) {
	node *ptr = array;
	while(ptr != NULL) {
		printf("%p: %s\n", ptr, ptr->word);
		ptr = ptr->next;
	}
}

int main() {
	int array_len = get_int("enter array length: ");
	printf("%d\n", array_len);
	if(array_len < 1) {
		printf("Length can`t be less than 1\n");
		exit(1);
	}
	node *array = malloc(sizeof(node));
	if(array == NULL){
		exit(1);
	}

	for(int i = 0; i < array_len; i++) {
		if(i == 0){
			array->word = get_string("Enter word: ");
			array->next = NULL;
			continue;
		}
		node *ptr = malloc(sizeof(node));
		if(ptr == NULL) {
			free(array);
		}

		ptr->word = get_string("Enter word: ");
		ptr->next = array;
		array = ptr;
	}
	print_array(array);
	return (0);
}
