/*
 Author: René Kliment <rene.kliment@gmail.com>
 */

#include<stdio.h>
#include<string.h>

/*
 returned error values:
 -1		wrong number of parameters
 -2		unrecongnized command
 */

int main(int argc, char **argv)
{

	if (argc != 2) {
		return -1;
	}

	char *command = argv[1];
	if (strcmp(command, "--normal") != 0
		&& strcmp(command, "--reversed") != 0
	) {
		return -2;
	}

	int c;
	char strng[129];

	int i;
	for (i=0; (c = getchar()) != EOF; i++) {
		strng[i] = c;
	}

	if (strcmp(command, "--normal") == 0) {
		for (int j=0; j < i; j++) {
			putchar(strng[j]);
		}
	} else if (strcmp(command, "--reversed") == 0) {
		for (i--; i >= 0; i--) {
			putchar(strng[j]);
		}
	}

	putchar('\n');

	return 0;
}