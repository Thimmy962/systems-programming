/**
* encodes and decodes a string or value
*/

#include <stdlib.h>
#include "func.c"

typedef struct {
	int value;
	int key;
}Result;


Result *encode(int value){ 
	value = value ^ 1000;
	Result *result = malloc(sizeof(Result));
	if(result == NULL)
		return (NULL);
	result->value = value;
	result->key = 1000;
	return result;
}
int decode(int cypher, int key){
	return cypher ^ key;
}


int main(){ 
	int value_to_encrypt = get_int("Enter value: ");
	Result *values = encode(value_to_encrypt);
	printf("Encode: %i\n", values->value);

	printf("Decode: %d\n", decode(values->value, values->key));
	free(values);
}
