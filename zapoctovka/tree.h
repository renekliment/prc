#ifndef _TREE_H_
#define _TREE_H_

enum {
	TREE_NULL = -1,
	TREE_MALLOC_ERROR = -2,
	TREE_DATA_NULL = -3,
	TREE_COMPARATOR_NULL = -4,
	TREE_ROOT_NULL = -5
};

struct TreeItem {
	struct TreeItem *parent;
	struct TreeItem *left;
	struct TreeItem *right;

	char index;
	char data[17];
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
  TREE_MALLOC_ERROR	memory allocattion error
*/
int addItem(Tree *tree, char index, char *data);

/* returns
  NULL	when (tree == NULL),
  NULL	when there is no such index in the tree
*/
char* findData(Tree *tree, char index);

void delNode(TreeItem *node);

// returns TREE_NULL when (tree == NULL)
int delTree(Tree *tree);

#endif