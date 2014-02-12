#include "ptree.h"
#include <stdlib.h>

int initializepTree(pTree *tree, int (*comparator)(const void*, const void*))
{
	if (tree == NULL) return PTREE_NULL;
	if (comparator == NULL) return PTREE_COMPARATOR_NULL;

	pTreeItem *root;
	root = (pTreeItem*)malloc(sizeof(pTreeItem));
	if (root == NULL) return PTREE_MALLOC_ERROR;

	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;
	root->index = ' ';

	tree->root = root;
	tree->compare = comparator;

	return 0;
}

int setBinaryPrefix(pTree *tree, char left, char right)
{
	if (tree == NULL) return PTREE_NULL;

	tree->left = left;
	tree->right = right;

	return 0;
}

int addpItem(pTree *tree, char index, char *prefix)
{
	if (tree == NULL) return PTREE_NULL;
	if (prefix == NULL) return PTREE_PREFIX_NULL;
	if (prefix[0] == '\0') return PTREE_PREFIX_NULL;

	pTreeItem *current = tree->root;

	int i;
	for (i=0; i < 16 + 1; i++) {

		if (prefix[i] == '\0') {

			current->index = index;

			return 0;

		} else if (prefix[i] == tree->left) {

			if (current->left == NULL) {

				pTreeItem *newItem;
				newItem = (pTreeItem*)malloc(sizeof(pTreeItem));
				if (newItem == NULL) return PTREE_MALLOC_ERROR;

				newItem->right = NULL;
				newItem->left = NULL;
				newItem->index = ' ';

				newItem->parent = current;
				current->left = newItem;
			}

			current = current->left;

		} else if (prefix[i] == tree->right) {

			if (current->right == NULL) {

				pTreeItem *newItem;
				newItem = (pTreeItem*)malloc(sizeof(pTreeItem));
				if (newItem == NULL) return PTREE_MALLOC_ERROR;

				newItem->right = NULL;
				newItem->left = NULL;
				newItem->index = ' ';

				newItem->parent = current;
				current->right = newItem;
			}

			current = current->right;

		}

	}

	return PTREE_PREFIX_ERROR;
}

int indexByPrefix(pTree *tree, char *prefix)
{
	if (tree == NULL) return PTREE_NULL;
	if (prefix == NULL) return PTREE_PREFIX_NULL;
	if (prefix[0] == '\0') return PTREE_PREFIX_NULL;


	pTreeItem *current = tree->root;

	int i;
	for (i=0; i < 16 + 1; i++) {

		if (prefix[i] == '\0') {

			if (current->index == ' ') return PTREE_NOT_FOUND;

			return current->index;

		} else if (prefix[i] == tree->left) {

			if (current->left == NULL) return PTREE_NOT_FOUND;
			current = current->left;

		} else if (prefix[i] == tree->right) {

			if (current->right == NULL) return PTREE_NOT_FOUND;
			current = current->right;

		}

	}

	return PTREE_PREFIX_ERROR;
}

void delpNode(pTreeItem *node)
{
	if (node == NULL) return;

	if (node->left != NULL)
		delpNode(node->left);

	if (node->right != NULL)
		delpNode(node->right);

	free(node);
}

int delpTree(pTree *tree)
{
	if (tree == NULL) return PTREE_NULL;

	if (tree->root != NULL) {
		delpNode(tree->root);
	}

	tree->root = NULL;
	tree->compare = NULL;

	return 0;
}
