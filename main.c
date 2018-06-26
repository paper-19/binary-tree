
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main()
{

	//debug
	int tree_ret;


	//ignore tree_open/tree_close cause I'll have to workout representing
	//it as an array..

	struct Tree tree;
	struct Tree * tree_ptr = &tree;

	tree_init(tree_ptr);

	tree_ret = tree_add(tree_ptr, 123);
	tree_ret = tree_add(tree_ptr, 12);
	tree_ret = tree_add(tree_ptr, 2411);
	tree_ret = tree_add(tree_ptr, 1231);
	tree_ret = tree_add(tree_ptr, 5);
	tree_ret = tree_add(tree_ptr, 6);
	tree_ret = tree_add(tree_ptr, 144);
	tree_ret = tree_add(tree_ptr, 144);
	tree_ret = tree_add(tree_ptr, 124);

	printf("Tree size: '%d'\n", tree_size(tree_ptr));

	tree_destroy(tree_ptr);

	return EXIT_SUCCESS;
}
