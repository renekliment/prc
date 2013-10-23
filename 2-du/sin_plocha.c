#include <stdio.h>
#include <math.h>

int main (void)
{
	float a,b;

	printf("Zadejte hranice intervalu oddelene mezerou: ");
	scanf("%f %f", &a, &b);

	if (a > b) { // this is not secure !!!!!!!!!!!!
		float temp;

		temp = a;
		a = b;
		b = temp;
	}

	printf("Plocha pod funkci (urcity integral) sin(x) v zadanem intervalu je: %f\n", cos(a) - cos(b));

	return 0;
}