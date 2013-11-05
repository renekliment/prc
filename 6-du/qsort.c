#include <stdio.h>

// porovna dve hodnoty typu int
int compare (const void *a, const void *b)
{
	if (*((int*)a) == *((int*)b)) {
		return 0;
	} else if (*((int*)a) > *((int*)b)) {
		return 1;
	}

	return -1;
}

// prehodi hodnoty na pozicich first a second
void swap (void *first, void *second, int size)
{
	if (first == second) return;
	int i;
	char *f = (char*)first;
	char *s = (char*)second;

	char tmp;

	for (i=0; i<size; i++) {
		tmp = *(f + i);
		*(f + i) = *(s + i);
		*(s + i) = tmp;
	}
}

// vysvetlete kod nasledujici funkce
void* partition (void *base, int n, int size, void *index, int(*compare)(const void*, const void*))
{
	int i;
	char *store = (char*)base; // nastavím store na začátek pole
	char *basec = (char*)base;
	swap (index, basec + (n - 1)*size, size); // hodím si pivot na konec
	for (i = 0; i < n - 1; i++) // procházím postupně danou část pole
	{
		if (compare(basec + i*size, basec + (n - 1)*size) <= 0) // pokud je aktuální prvek menší nebo rovno, než pivot
		{
			swap(basec + i*size, store, size); // tak ho dám "doleva" pole ... takhle tam budu tlačit postupě prvky < pivot
			store += size; // index te kopy nalevo posunu doprava
		}
	}
	swap(store, basec + (n - 1)*size, size); // hodím pivot tam, kam má být
	return store;
}

void my_qsort (void *base, int n, int size, int(*compare)(const void*, const void*))
{
	if (n <= 1) return;
	char* basec = (char*)base;
	char *newp = (char*)partition(base, n, size, basec + ((n - 1) / 2)*size, compare);

	// doplnte volani funkci
	// leva podcast aktualni casti
	my_qsort(base, (int)( newp - basec)/size, size, compare);
	// prava podcast aktualni casti
	my_qsort(newp + size, n - 1 - (int)(newp - basec)/size, size, compare);
}

int main(int argc, char **argv)
{
	int pole[10] = {1, 3, 2, 1, 6, 4, 8, 2, 3, 5};
	int i;

	// 3 je vetsi nez 2
	//printf("compare vraci %d\n", compare(&pole[1], &pole[2]));

	// 1 je mensi nez 6
	//printf("compare vraci %d\n", compare(&pole[3], &pole[4]));

	// 1 se rovna 1
	//printf("compare vraci %d\n", compare(&pole[3], &pole[3]));

	// prehodi prvek 0 a 1
	// swap(&pole[0], &pole[1], sizeof(int));

	for (i = 0; i < 10; i++) {
		printf("%d ", pole[i]);
	}

	putchar('\n');

	my_qsort(pole, 10, sizeof(int), compare);

	for (i = 0; i < 10; i++) {
		printf("%d ", pole[i]);
	}

	putchar('\n');

	return 0;
}