#ifndef _P_TREE_H_
#define _P_TREE_H_

enum {
	PTREE_NULL = -1,
	PTREE_MALLOC_ERROR = -2,
	PTREE_WRONG_SIZE = -3,
	PTREE_COMPARATOR_NULL = -4,
	PTREE_ROOT_NULL = -5,
	PTREE_PREFIX_NULL = -6,
	PTREE_PREFIX_ERROR = -7,
	PTREE_NOT_FOUND = -8
};

struct pTreeItem {
	struct pTreeItem *parent;
	struct pTreeItem *left;
	struct pTreeItem *right;

	char index;
};

typedef struct pTreeItem pTreeItem;

typedef struct {
	pTreeItem *root;
	int (*compare)(const void*, const void*);

	char left;
	char right;
} pTree;

/* returns
  PTREE_NULL			when (tree == NULL)
  PTREE_COMPARATOR_NULL	when (comparator == NULL)
  PTREE_MALLOC_ERROR	on memory allocation error
 */
int initializepTree(pTree *tree, int (*comparator)(const void*, const void*));

// returns PTREE_NULL when (tree == NULL)
int setBinaryPrefix(pTree *tree, char left, char right);

/* returns
  PTREE_NULL			when (tree == NULL),
  PTREE_PREFIX_NULL		when (prefix == NULL)
  PTREE_PREFIX_NULL		when (prefix[0] == '\0')
  PTREE_MALLOC_ERROR	on memory allocation error
  PTREE_PREFIX_ERROR	when valid prefix is longer than 16 characters
*/
int addpItem(pTree *tree, char index, char *prefix);

/* returns
  PTREE_NULL			when (tree == NULL),
  PTREE_PREFIX_NULL		when (prefix == NULL)
  PTREE_PREFIX_NULL		when (prefix[0] == '\0')
  PTREE_NOT_FOUND		when node witch such prefix is not in the tree
  PTREE_PREFIX_ERROR	when valid prefix is longer than 16 characters
*/
int indexByPrefix(pTree *tree, char *prefix);

void delpNode(pTreeItem *node);

// returns PTREE_NULL when (tree == NULL)
int delpTree(pTree *tree);

#endif