#include "func.c"


/**
* checkbit - checks if the bit at a particular position is 1
* @num: the number whose bit we are checkinh
* @pos: the position we want to check
* return: true if the bit at pos of num is 1 else 0
* positon is zero indexed
*/
bool checkbit(int num, int pos)
{
	if(pos > sizeof(int) || pos < 1)
	{
		printf("Postion can only be between 1 and %ld\n", sizeof(int) * 8);
		exit(1);
	}
	num = num >> pos;
	return num & 1;	
}


int main()
{
	int num = get_int("Get number: ");
	int pos = get_int("Enter position: ");
	if(!checkbit(num, pos))
	{
		printf("False\n");
	}
	else{
		printf("True\n");
	}
}
