#include <stdio.h>
#include <stdlib.h>

enum {
	STATUS_OK = 0,
	NEGATIVE_MATRIX_DIMENSION = 1,
	MEMORY_ALLOCATION_ERROR = 2
};

int main(void)
{
	int n;
	int i,j,k;

	/* Dimension of matrices */
	scanf("%d", &n);
	if (n < 0) return NEGATIVE_MATRIX_DIMENSION;

	/* Memory allocation */
	int *matrix1;
	int *matrix2;
	int *matrix3;

	matrix1 = (int*)malloc(n*n*sizeof(int));
	if (matrix1 == NULL) return MEMORY_ALLOCATION_ERROR;

	matrix2 = (int*)malloc(n*n*sizeof(int));
	if (matrix2 == NULL) {
		free(matrix1);
		return MEMORY_ALLOCATION_ERROR;
	}

	matrix3 = (int*)calloc(n*n, sizeof(int));
	if (matrix3 == NULL) {
		free(matrix1);
		free(matrix2);
		return MEMORY_ALLOCATION_ERROR;
	}

	/* Input */
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			scanf("%d", &matrix1[n*i + j]);
		}
	}

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			scanf("%d", &matrix2[n*i + j]);
		}
	}

	putchar('\n');

	/* matrix1 * matrix2 */
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			for (k=0; k<n; k++) {
				matrix3[n*i + j] += matrix1[n*i + k] * matrix2[n*k + j];
			}
			printf("%d ", matrix3[n*i + j]);
		}

		putchar('\n');
	}

	free(matrix1);
	free(matrix2);
	free(matrix3);

	putchar('\n');

	return STATUS_OK;
}