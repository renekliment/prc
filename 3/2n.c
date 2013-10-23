#include <stdio.h>

int main (void)
{
	int n;

	scanf("%d", &n);

	printf("2^%u = %u \n",
			n,
			1 << n
	);

	return 0;
}