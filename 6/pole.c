#include <stdio.h>

#define ARR_SZ 4

int main(void)
{
	int pole[ARR_SZ] = {1, 2, 3, 4};

	int i;
	for (i=0; i<ARR_SZ; i++) {
		printf("%d ", *(pole + i));
	}

	putchar('\n');

	for (i=ARR_SZ - 1; i>=0; i--) {
		printf("%d ", *(pole + i));
	}

	putchar('\n');

	return 0;
}