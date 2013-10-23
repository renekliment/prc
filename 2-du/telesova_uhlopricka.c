#include <stdio.h>
#include <math.h>

/*
 error codes:
 -1		input variable is not in specified range
 */

int main (void)
{
	float a;

	printf("Zadejte delku hrany krychle: ");
	scanf("%f", &a);

	if (a < 0) { // beware of comparing floats without giving it much thought ... can get very tricky!
		printf("Delka nemuze byt zaporne cislo! Bye!\n");
		return -1;
	}

	printf("Telesova uhlopricka krychle je: %f\n", sqrt(3)*a);

	return 0;
}