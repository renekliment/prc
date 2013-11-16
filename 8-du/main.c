#include "list.h"
#include <stdio.h>

int main (int argc, char **argv)
{
	List list1;
	initializeList(&list1);

	int i;
	for (i = 0; i < 10; i++) addItem (&list1, &i);

	delItemP(&list1, 9);
	delItemP(&list1, 0);
	delItemP(&list1, 5);

	i = 4;
	T *ip = findFirst(&list1, &i);
	if (ip) *ip = 6;

	for (i = 0; i < getLength(&list1); i++) {
		printf("%d ", *getItem(&list1, i));
	}

	delAll(&list1);

	putchar('\n');

	return 0;
}