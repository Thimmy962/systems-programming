#include "func.c"

/**
* clearbit - sets the bit at a position to 0
* @num: the number whose bit is to be l=cleared
* @pos: position to clear
* return: the new number
*/

int clearbit(int num, int pos)
{
	int mask = 1 << pos;
	return num ^ mask;
}

int main()
{
	int num = get_int("Enter number: ");
	int pos = get_int("Enter position: ");
	int cleared = clearbit(num, pos);
	printf("Cleared bit resulted in: %d\n", cleared);
	return (0);
}
