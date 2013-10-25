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

		if (c >= 'A' && c <= 'Z') {
			c += ('a' - 'A');
		}

		if ((c >= 'a' && c <= 'z')
			|| c == ' '
			|| c == '\n'
		) {
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