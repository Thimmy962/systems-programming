#include <stdio.h>
#include <stdlib.h>

int get_int(char *query)
{
	int value;
	printf("%s", query);
	scanf("%i", &value);
	return (value);
}

int main()
{
	int value = get_int("Enter array size: ");

	int *array = malloc(value * sizeof(int));
	int arr_total = 0;
	int i = 0;
	while (i < value)
	{
		*(array+i) = get_int("Enter value of array: ");
		i++;
	}

	for(int i = 0; i < value; i++)
	{
		arr_total += *(array+i);
	}

	printf("Total: %i\n", arr_total);
	free(array);

	return (0);
}
