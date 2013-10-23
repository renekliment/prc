#include <stdio.h>
#include <math.h>

int main(void)
{
	float a,b,c;

	printf("Zadejte koeficienty kvadraticke rovnice a,b,c oddelene mezerou: ");
	scanf("%f %f %f", &a, &b, &c);

	/*
	if (a == 0) {
		printf("Koeficient nemuze byt 0! Bye!");
		return -1;
	}
	*/

	printf("x_1 = %f\n", (-b + sqrt(b*b - 4*a*c))/(2*a) );
	printf("x_2 = %f\n", (-b - sqrt(b*b - 4*a*c))/(2*a) );

	return 0;
}