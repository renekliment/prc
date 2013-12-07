/*
 Author: René Kliment <rene.kliment@gmail.com>
 */

#include <stdio.h>
#include "tree.h"

#define INSERT_ARRAY_SIZE 9

int int_comparator(const void *first, const void *second)
{
	int *a = (int*)first;
	int *b = (int*)second;

	if (*a < *b) {
		return -1;
	} else if (*a > *b) {
		return 1;
	}

	return 0;
}

int main(int argc, char **argv)
{
	Tree maple;

	initializeTree(&maple, int_comparator);

	int insertArray[INSERT_ARRAY_SIZE] = {6, 8, 4, 4654, 1, 5, 7, 2, 10};
	int i;
	for (i=0; i < INSERT_ARRAY_SIZE; i++) {
		addItem(&maple, sizeof(int), insertArray + i);
	}

	printf("Minimum: %d\n", *((int*)min(&maple)) );
	printf("Maximum: %d\n", *((int*)max(&maple)) );

	minDel(&maple);
	maxDel(&maple);

	printf("Minimum: %d\n", *((int*)min(&maple)) );
	printf("Maximum: %d\n", *((int*)max(&maple)) );

	delTree(&maple);


	return 0;
}