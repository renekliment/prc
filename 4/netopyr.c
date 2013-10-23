#include<stdio.h>

int main (int argc, char **argv)
{
	/*int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
	}*/

	int c;
	char retezec[129];

	int i;
	for (i=0; (c = getchar()) != EOF; i++) {
		retezec[i] = c;
	}

	for (i--; i >= 0; i--) {
		putchar(retezec[i]);
	}

	putchar('\n');

	return 0;
}