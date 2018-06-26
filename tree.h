
#ifndef TREE_H_
#define TREE_H_

/**/
struct Node {
	struct Node * left;
	struct Node * right;
	int value;
};

/**/
struct Tree {
	struct Node * root;
	int size;
};

/**/
struct Tree * tree_open(const char * filename);
/**/
int tree_close(struct Tree * tree);
/**/
void tree_init(struct Tree * tree);
/**/
void tree_destroy(struct Tree * tree);
/* Returns the number of elements within the tree */
int tree_size(struct Tree * tree);
/* Adds the value to the collection */
int tree_add(struct Tree * tree, int value);
/* Returns 1 if the value is in the collection, 0 otherwise */
int tree_contains(struct Tree * tree, int value);
/* Returns 1 if the value was in the collection and removed, 0 otherwise */
int tree_remove(struct Tree * tree, int value);

#endif /* TREE_H_ */

