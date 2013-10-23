#include<stdio.h>

int main(void)
{
	char c;

	while ((c = getchar()) != EOF) {
// also possible
/*
		if (c != 'a'
			&& c != 'e'
			&& c != 'i'
			&& c != 'o'
			&& c != 'u'
		) {
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