#include <stdio.h>
#include <math.h>

int main(void)
{
	float r;

	printf("Zadejte polomer kruhu: ");
	scanf("%f", &r);

	printf("Obsah kruhu je: %f\n", M_PI*r*r);

	return 0;
}