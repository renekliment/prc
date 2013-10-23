/*
 This is a simple C app that computes definite integral in a specified interval of a predefined function using the Monte Carlo method.
 The interval and number of "shots" is read from the user via interactive command-line interface.
 The function to integrate can be changed in the source code.

 Author: René Kliment <rene.kliment@gmail.com>
 */

#include <stdio.h>

#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include <math.h>

//##############################################
const float MC_INT_MIN = 0;
const float MC_INT_MAX = 3.1416;
const float MC_F_MAX = 1;

#define f(x) sin(x)
#define f_analytic_integral(a,b) cos(a)-cos(b)

//##############################################

int main (int argc, char **argv)
{
	int n, hit;
	float a,b;
	int show_stages;

	printf("Zadejte interval: ");
	scanf("%f %f", &a, &b);
	if (a < MC_INT_MIN || b > MC_INT_MAX || MC_INT_MIN > MC_INT_MAX) {
		printf("Neplatne hranice intervalu!\n");
		return -1;
	}

	printf("Zadejte pocet vystrelu: ");
	scanf("%d", &n);
	if (n < 0) {
		printf("Pocet vystrelu nemuze byt zaporny!\n");
		return -2;
	}

	printf("Chcete zobrazit prubeh? (1=ano, 0=ne): ");
	scanf("%d", &show_stages);
	if (show_stages != 1) {
		show_stages = 0;
	}
	printf("\n");

	/*
		Inicializace generátoru pseudonáhodných čísel.
		Zde využíváme jako počáteční hodnotu aktuální čas v systému.
	*/
	srand(time(0));

	float rand_n1, rand_n2, rand_x, rand_y;
	float result_an, result_mc;

	result_an = f_analytic_integral(a,b);

	if (show_stages) {
		printf("Integral f analyticky: %f\n", result_an);
		printf("#SHOTS\tINTEGRAL\tERROR\t\tERROR %%\n");
	}
	printf("===============================================================\n");

	int i;
	for (i=0; i<n; i++) {
		// vygenerování čísla s rovnoměrným rozdělením v intervalu [0, 1)
		rand_n1 = rand()/(1.0 + RAND_MAX);
		rand_n2 = rand()/(1.0 + RAND_MAX);

		rand_x = a + rand_n1*(b-a);
		rand_y = rand_n2 * MC_F_MAX;

		if (f(rand_x) > rand_y) {
			hit++;
		}

		if (show_stages) {
			result_mc = ((float)hit/n)*(b-a)*MC_F_MAX;
			printf("%d\t%f\t%f\t%f%% \n", i+1, result_mc, result_mc - result_an, (fabs(1 - fabs(result_mc/result_an)))*100 );
		}
	}

	if (!show_stages) {
		result_mc = ((float)hit/n)*(b-a)*MC_F_MAX;
		printf("Integral f metodou Monte Carlo: %f \n", result_mc);
		printf("Integral f analyticky         : %f\n", result_an);
		printf("Chyba Monte Carlo             : %f (%f%%)\n", result_mc - result_an, (fabs(1 - fabs(result_mc/result_an)))*100 );
	} else {
		printf("===============================================================\n");
		printf("Integral f analyticky: %f\n", result_an);
	}

	return 0;
}