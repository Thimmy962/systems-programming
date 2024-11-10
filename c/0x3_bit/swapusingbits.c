#include"func.c"
/**
* swapnums - swaps the value of 2 int values using  bitwise operators
* @numa: pointer to one of the values to swap
* @numb: pointer one of the values to swap
*/

void swapnums(int *numa, int *numb) {
	*numa = *numa ^ *numb;
	*numb = *numb ^ *numa;
	*numa =  *numa ^ *numb;
}


int main(){
	int numa = get_int("Enter value A: ");
	int numb = get_int("Enter value B: ");

	printf("Value of A and B before swapping are %d and %d\n", numa, numb);

	swapnums(&numa, &numb);

	printf("Value of A and B before swapping are %d and %d\n", numa, numb);
}
