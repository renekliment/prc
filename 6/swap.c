#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

int main(void)
{
	int a,b;

	a = 3;
	b = 5;

	printf("A: %d, B: %d\n", a, b);

	swap(&a, &b);

	printf("A: %d, B: %d\n", a, b);

	return 0;
}