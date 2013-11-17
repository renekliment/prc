#include "list.h"
#include <stdlib.h>

int initializeList(List *list)
{
	if (list == NULL) return -1;

	list->first = NULL;
	list->last = NULL;
	list->length = 0;

	return 0;
}

int getLength(List *list)
{
	if (list == NULL) return -1;

	return list->length;
}

int addItem(List *list, T *item)
{
	if (list == NULL || item == NULL) return -1;

	ListItem *newItem;
	newItem = (ListItem*)malloc(sizeof(ListItem));
	if (newItem == NULL) return -2;

	newItem->next = NULL;
	newItem->item = *item;

	if (list->length == 0) {
		list->first = newItem;
	} else {
		list->last->next = newItem;
	}
	list->last = newItem;

	list->length++;

	return 0;
}

T* getItem(List *list, int pos)
{
	if (list == NULL || pos < 0 || pos >= list->length) return NULL;

	ListItem *current;
	current = list->first;

	for (int i=0; i < pos; i++) {
		current = current->next;
	}

	return &current->item;
}

T* findFirst(List *list, T* item)
{
	if (list == NULL) return NULL;

	ListItem *current;
	current = list->first;

	for (int i=0; i < list->length; i++) {
		if (current->item == *item) {
			return &current->item;
		}
		current = current->next;
	}

	return NULL;
}

int delItemP(List *list, int pos)
{
	if (list == NULL || pos < 0 || pos >= list->length) return -1;

	list->length--;

	ListItem *temp;

	if (pos == 0) {

		temp = list->first;
		list->first = list->first->next;
		free(temp);

		if (list->first == list->last) {
			list->last = NULL;
		}

	} else {

		ListItem *previous, *current;
		previous = list->first;
		current = list->first->next;

		for (int i=1; i < pos; i++) {
			previous = current;
			current = current->next;
		}

		if (current->next == NULL) {
			free(current);
			previous->next = NULL;
			list->last = previous;

			return 0;
		}

		temp = current;
		previous->next = current->next;
		free(temp);

	}

	return 0;
}

void delAll(List *list)
{
	if (list == NULL || list->length == 0) return;

	ListItem *previous, *current;
	previous = list->first;

	while (previous != NULL) {
		current = previous->next;
		free(previous);
		previous = current;
	}

	list->first = NULL;
	list->last = NULL;
	list->length = 0;
}