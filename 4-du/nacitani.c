/*
 Author: René Kliment <rene.kliment@gmail.com>
 */

#include<stdio.h>

int main(int argc, char **argv)
{
	char c;
	int num=0;

	while ((c = getchar()) != EOF) {

		if (c >= '0' && c <= '9') {
			num = 10*num + (c - '0');
		} else {
			printf("Chybny vstup!\n");
			return -1;
		}

	}

	printf("\n%d\n", num);

	return 0;
}