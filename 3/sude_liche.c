#include <stdio.h>

int main (void)
{
	int a;
	scanf("%d", &a);

	if ((a & 1) == 0) {
		printf("Cislo je sude.\n");
	} else {
		printf("Cislo je liche.\n");
	}

	return 0;
}