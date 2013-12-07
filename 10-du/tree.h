#ifndef _TREE_H_
#define _TREE_H_

enum {
	TREE_NULL = -1,
	TREE_MALLOC_ERROR = -2,
	TREE_DATA_NULL = -3,
	TREE_WRONG_SIZE = -4,
	TREE_COMPARATOR_NULL = -5,
	TREE_ROOT_NULL = -6
};

struct TreeItem {
	struct TreeItem *parent;
	struct TreeItem *left;
	struct TreeItem *right;

	void *data;
};

typedef struct TreeItem TreeItem;

typedef struct {
	TreeItem *root;
	int (*compare)(const void*, const void*);
} Tree;

/* returns
  TREE_NULL				when (tree == NULL)
  TREE_COMPARATOR_NULL	when (comparator == NULL)
 */
int initializeTree(Tree *tree, int (*comparator)(const void*, const void*));

/* returns
  TREE_NULL			when (tree == NULL),
  TREE_DATA_NULL	when (data == NULL),
  TREE_WRONG_SIZE	when (size <= 0),
  TREE_MALLOC_ERROR on memory allocation error
*/
int addItem(Tree *tree, int size, void *data);

/* returns
  NULL when (tree == NULL)
  NULL when (tree->root == NULL)
*/
void* max(Tree *tree);

/* returns
  NULL when (tree == NULL)
  NULL when (tree->root == NULL)
*/
void* min(Tree *tree);

/* returns
  TREE_NULL when (tree == NULL)
  TREE_ROOT_NULL when (tree->root == NULL)
*/
int maxDel(Tree *tree);

/* returns
  TREE_NULL when (tree == NULL)
  TREE_ROOT_NULL when (tree->root == NULL)
*/
int minDel(Tree *tree);

void delNode(TreeItem *node);

// returns TREE_NULL when (tree == NULL)
int delTree(Tree *tree);

#endif