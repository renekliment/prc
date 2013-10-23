/*
 Author: René Kliment <rene.kliment@gmail.com>
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 returned error values:
 -1		wrong number of parameters
 -2		unrecongnized command
 */

int main(int argc, char **argv)
{
	char txt_encrypt[] = "--encrypt";
	char txt_decrypt[] = "--decrypt";

	/* Input checks */
	if (argc != 3) {
		return -1;
	}

	char *command = argv[1];
	if (strcmp(command, txt_encrypt) != 0
		&& strcmp(command, txt_decrypt) != 0
	) {
		return -2;
	}

	/* Let's check the shift given by user is a nice value and do sthing with it if it's not */
	int shift;
	shift = atoi(argv[2]);

	if (shift >= 'Z' - 'A' + 1) {
		shift %= 'Z' - 'A' + 1;
	}

	if (strcmp(command, txt_decrypt) == 0) {
		shift *= -1;
	}

	/* Encrypt, decrypt, yay! */
	int c;

	while ((c = getchar()) != EOF) {
		if ((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')
		) {
			if (c >= 'A' && c <= 'Z') {
				c += ('a' - 'A');
			}

			c += shift;
			if (c > 'z') {
				c = 'a' - 1 + (c - 'z');
			} else if (c < 'a') {
				c = 'z' + 1 - ('a' - c);
			}

			putchar(c);
		} else if (c == ' ') {
			putchar(c);
		}

	}

	putchar('\n');

	return 0;
}