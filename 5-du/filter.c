#include<stdio.h>

int main(void)
{
	char c;

	while ((c = getchar()) != EOF) {
/*
		if (c == 'a'
			|| c == 'e'
			|| c == 'i'
			|| c == 'o'
			|| c == 'u'
		) {

		} else {
			putchar(c);
		}
*/

		switch (c) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				break;

			default:
				putchar(c);
				break;
		}
	}

	putchar('\n');

	return 0;
}