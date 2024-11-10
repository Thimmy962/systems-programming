#include "func.c"

/**
* setbit - sets the bit at a particular position to 1
* @num: the number whose bits to manipulate
* @pos: the position to manipulate (zero indexed)
* return: a new 
*/

int setbit(int num, int pos)
{
	if(pos > sizeof(int) * 8 || pos < 0)
	{
		printf("Position of bit must be between 1 and %ld\n", (sizeof(int) * 8));
	}
	return num | (1 << pos);
}

int main()
{
	int num = get_int("Get number: ");
	int pos = get_int("Get position: ");

	int new_int = setbit(num, pos);
	printf("Result is: %d\n", new_int);
}
