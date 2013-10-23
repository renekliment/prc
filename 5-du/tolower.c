#include<stdio.h>

/*
 return values:
 0		OK
 -1		wrong input
 */

int main(void)
{
	char c;

	while ((c = getchar()) != EOF) {

		if (c == ' '
			|| c == '\n'
			|| (c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')
		) {
			if (c >= 'A' && c <= 'Z') {
				c += ('a' - 'A');
			}

			putchar(c);

			if (c == '\n') {
				break;
			}
		} else {
			return -1;
		}

	}

	putchar('\n');

	return 0;
}