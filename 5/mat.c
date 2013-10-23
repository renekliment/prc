#include<stdio.h>

int main(void)
{
	int matrix1[3][3];
	int matrix2[3][3];
	int matrix3[3][3] = {};

	int i,j,k;

	/* Input */
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			scanf("%d", &matrix1[i][j]);
		}
	}

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			scanf("%d", &matrix2[i][j]);
		}
	}

	putchar('\n');

	/* Echo */
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			printf("%d ", matrix1[i][j]);
		}
		putchar('\n');
	}

	putchar('\n');

	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			printf("%d ", matrix2[i][j]);
		}
		putchar('\n');
	}

	putchar('\n');

	/* matrix1 * matrix2 */
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			for (k=0; k<3; k++) {
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			}
			printf("%d ", matrix3[i][j]);
		}

		putchar('\n');
	}

	putchar('\n');

	return 0;
}