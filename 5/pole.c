#include<stdio.h>

#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define DELKA_POLE 30

void insertion_sort(int array[], int size)
{
	int value,j;

	for (int i=0; i<size; i++) {
		value = array[i];
		j = i-1;

		for (; (j >= 0 && array[j] > value); j--) {
			array[j+1] = array[j];
		}
		array[j+1] = value;
	}
}

int main(void)
{
	int pole[DELKA_POLE];
	int i;

	srand(time(0));

	for (i=0; i<DELKA_POLE; i++) {
		pole[i] = rand() % 100;
	}

	insertion_sort(pole, DELKA_POLE);

	for (i=0; i<DELKA_POLE; i++) {
		printf("%d ", pole[i]);
	}

	putchar('\n');

	for (i=DELKA_POLE-1; i>=0; i--) {
		printf("%d ", pole[i]);
	}

	putchar('\n');

	return 0;
}