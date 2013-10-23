#include <stdio.h>

int main(void)
{
	int a;
	int b;

	printf("Zadejte dve cisla oddelena mezerou: ");
	scanf("%d %d", &a, &b);

	printf("a + b = %d\n", (a + b));
	printf("a - b = %d\n", (a - b));
	printf("a * b = %d\n", (a * b));
	printf("a / celociselne b = %d\n", (a / b));
	printf("a %% b = %d\n", (a % b));
	printf("a / b = %.3f\n", ((float )a / b));

	return 0;
}