#include<stdio.h>
#include<math.h>

#define DIM 3
#define FLOAT_PREC 0.000001

int main(void)
{
	float mat[DIM][DIM];
	int i,j;
	float det;

	for (i=0; i<DIM; i++) {
		for (j=0; j<DIM; j++) {
			scanf("%f", &mat[i][j]);
		}
	}

	/* Works for DIM=3 only, so it actually needs to be adjusted, if you need another matrix dimension */
	det = mat[0][0]*mat[1][1]*mat[2][2]
		 +mat[1][0]*mat[2][1]*mat[0][2]
		 +mat[2][0]*mat[0][1]*mat[1][2]
		 -mat[0][2]*mat[1][1]*mat[2][0]
		 -mat[1][2]*mat[2][1]*mat[0][0]
		 -mat[2][2]*mat[0][1]*mat[1][0];

	if (fabs(det) < FLOAT_PREC) {
		printf("Error: Matrix is not invertible!\n");
		return -1;
	}

	for (i=0; i<DIM; i++) {
		for (j=0; j<DIM; j++) {
			printf("%f ", (1/det)*mat[j][i]);
		}

		putchar('\n');
	}

	putchar('\n');

	return 0;
}