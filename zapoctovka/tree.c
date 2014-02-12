#include "tree.h"
#include <stdlib.h>

int initializeTree(Tree *tree, int (*comparator)(const void*, const void*))
{
	if (tree == NULL) return TREE_NULL;
	if (comparator == NULL) return TREE_COMPARATOR_NULL;

	tree->root = NULL;
	tree->compare = comparator;

	return 0;
}

int addItem(Tree *tree, char index, char *data)
{
	if (tree == NULL) return TREE_NULL;
	if (data == NULL) return TREE_DATA_NULL;

	TreeItem *newItem;
	newItem = (TreeItem*)malloc(sizeof(TreeItem));
	if (newItem == NULL) return TREE_MALLOC_ERROR;

	int i;
	char c;
	for (i=0; (c = data[i]) != '\0'; i++) {
		newItem->data[i] = c;
	}
	newItem->data[i] = '\0';

	newItem->left = NULL;
	newItem->right = NULL;
	newItem->index = index;

	if (tree->root != NULL) {
		TreeItem *parent = tree->root;
		char side;

		while (1) {
			if (tree->compare(&index, &parent->index) <= 0) {

				if (parent->left == NULL) {
					side = 0;
					break;
				}
				parent = parent->left;

			} else {

				if (parent->right == NULL) {
					side = 1;
					break;
				}
				parent = parent->right;

			}
		}

		newItem->parent = parent;
		if (side == 0) {
			parent->left = newItem;
		} else {
			parent->right = newItem;
		}
	} else {
		newItem->parent = NULL;
		tree->root = newItem;
	}

	return 0;
}

char* findData(Tree *tree, char index)
{
	if (tree == NULL) return NULL;

	TreeItem *node = tree->root;

	int cmp;
	while (1) {
		cmp = tree->compare(&index, &(node->index) );

		if (cmp == 0) {

			return (char*)&node->data;

		} else if (cmp == -1) {

			if (node->left == NULL)
				return NULL;

			node = node->left;

		} else if (cmp == 1) {

			if (node->right == NULL)
				return NULL;

			node = node->right;

		}

	}

	return NULL;
}

void delNode(TreeItem *node)
{
	if (node == NULL) return;

	if (node->left != NULL)
		delNode(node->left);

	if (node->right != NULL)
		delNode(node->right);

	free(node);
}

int delTree(Tree *tree)
{
	if (tree == NULL) return TREE_NULL;

	if (tree->root != NULL) {
		delNode(tree->root);
	}

	tree->root = NULL;
	tree->compare = NULL;

	return 0;
}
