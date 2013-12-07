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

int addItem(Tree *tree, int size, void *data)
{
	if (tree == NULL) return TREE_NULL;
	if (data == NULL) return TREE_DATA_NULL;
	if (size <= 0) return TREE_WRONG_SIZE;

	TreeItem *newItem;
	newItem = (TreeItem*)malloc(sizeof(TreeItem));
	if (newItem == NULL) return TREE_MALLOC_ERROR;

	void *newItemData;
	newItemData = malloc(size);
	if (newItemData == NULL) {
		free(newItem);
		return TREE_MALLOC_ERROR;
	}

	int i;
	for (i=0; i< size; i++) {
		*((char*)newItemData + i) = *((char*)data + i);
	}

	newItem->left = NULL;
	newItem->right = NULL;
	newItem->data = newItemData;

	if (tree->root != NULL) {
		TreeItem *parent = tree->root;
		char side;

		while (1) {
			if (tree->compare(data, parent->data) <= 0) {

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

void* max(Tree *tree)
{
	if (tree == NULL) return NULL;
	if (tree->root == NULL) return NULL;

	TreeItem *current = tree->root;

	while (current->right != NULL) {
		current = current->right;
	}

	return current->data;
}

void* min(Tree *tree)
{
	if (tree == NULL) return NULL;
	if (tree->root == NULL) return NULL;

	TreeItem *current = tree->root;

	while (current->left != NULL) {
		current = current->left;
	}

	return current->data;
}

int maxDel(Tree *tree)
{
	if (tree == NULL) return TREE_NULL;
	if (tree->root == NULL) return TREE_ROOT_NULL;

	TreeItem *current = tree->root;

	while (current->right != NULL) {
		current = current->right;
	}

	if (current->left != NULL) {
		current->parent->right = current->left;
	} else {
		current->parent->right = NULL;
	}

	free(current->data);
	free(current);

	return 0;
}

int minDel(Tree *tree)
{
	if (tree == NULL) return TREE_NULL;
	if (tree->root == NULL) return TREE_ROOT_NULL;

	TreeItem *current = tree->root;

	while (current->left != NULL) {
		current = current->left;
	}

	if (current->right != NULL) {
		current->parent->left = current->right;
	} else {
		current->parent->left = NULL;
	}

	free(current->data);
	free(current);

	return 0;
}

void delNode(TreeItem *node)
{
	if (node == NULL) return;

	if (node->left != NULL)
		delNode(node->left);

	if (node->right != NULL)
		delNode(node->right);

	free(node->data);
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
