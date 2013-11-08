#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b)
{
	if (*((int*)a) == *((int*)b)) {
		return 0;
	} else if (*((int*)a) > *((int*)b)) {
		return 1;
	}

	return -1;
}

int main(void)
{
	int n;
	int *array;

	printf("Zadejte pocet polozek pole: ");
	scanf("%d", &n);

	array = (int*)malloc(n*sizeof(int));
	if (array == NULL) {
		printf("Out of memory!");
	}

	int i;
	for (i=0; i<n; i++) {
		scanf("%d", &array[i]);
	}

	qsort(array, n, sizeof(int), compare);

	printf("Pole: ");
	for (i=0; i<n; i++) {
		printf("%d ", array[i]);
	}

	free(array);

	putchar('\n');

	return 0;
}