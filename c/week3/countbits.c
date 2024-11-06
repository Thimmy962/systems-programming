/**
* count_bit - counts the number of bits in the binary of a number
* @num: the number whose bit to count
* return: the number of bit(s) in the numbers binary
*/
#include "func.c"

int countbits(int num)
{
	int bits = 0;
	for(int i = 0; i < sizeof(int) * 8; i++)
	{
		/*
			shift the number by the value of i
			if the new value &(bitwise and) 1 == 1
			add to the number of bit
		*/
		if((num >> i) & 1 == 1){
			bits ++;
		}
	}
	return bits;
}

int main(){
	int num = get_int("Enter number: ");
	int num_bit_count = countbits(num);
	printf("Number of bits: %i\n", num_bit_count);
	return (0);
}
