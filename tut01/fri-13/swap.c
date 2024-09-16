#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void) {
	int a = 5;
	int b = 7;
	// print the addresses to a and b in the main function
	printf("address of a in main: %p\n", &a);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
		
	return 0;
}

void swap(int *a, int *b) {
	// print the addresses to a and b in this function
	printf("address of a in swap: %p\n", a);

	int tmp = *a;
	a = b;
	*a = *b;
	*b = tmp;

}



