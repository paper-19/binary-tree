
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

#define OP_FAIL 0
#define OP_SUCCESS 1

static int node_init(struct Node * node, int value);
static void node_destroy(struct Node * node);
static int node_add(struct Node * node, int value);
static int node_contains(struct Node * node, int value);

/**/
struct Tree * tree_open(const char * filename)
{
	FILE * file;
	file = fopen(filename, "r");
	//parse file into tree;
	//return tree;
}

/**/
void tree_init(struct Tree * tree)
{
	tree->root = NULL;
	tree->size = 0;
}

/**/
void tree_destroy(struct Tree * tree)
{
	if(tree->root)
	{
		node_destroy(tree->root);		
	}
}

/**/
int tree_size(struct Tree * tree)
{
	return tree ? tree->size : 0;
}

/**/
int tree_add(struct Tree * tree, int value)
{
	if(tree->root == NULL)
	{
		struct Node * node = NULL;
		node = malloc(sizeof(node) / sizeof(&node));
		if(node)
		{
			node_init(node, value);

			tree->root = node;
			tree->size++;

			return OP_SUCCESS;
		} else return OP_FAIL;
	}
	else
	{
		if(node_add(tree->root, value)) {
			tree->size++;
			return OP_SUCCESS;
		} else return OP_FAIL;
	}
}

/**/
int tree_contains(struct Tree * tree, int value)
{

	return OP_SUCCESS;
}

/**/
int tree_remove(struct Tree * tree, int value)
{
	return OP_SUCCESS;
}

/**/
static int node_init(struct Node * node, int value)
{
	node->left = NULL;
	node->right = NULL;
	node->value = value;
}

/**/
static void node_destroy(struct Node * node)
{
	if(node->left) node_destroy(node->left);
	if(node->right) node_destroy(node->right);

	printf("destroying node with value: '%d'\n", node->value);
	
	free(node);
}

/**/
static int node_add(struct Node * node, int value)
{

	struct Node * new_node;

	new_node = NULL;
	
	if(node->value < value)
	{
		if(node->left == NULL)
		{
			new_node = malloc(sizeof(new_node) / sizeof(&new_node));
			if(!new_node) return OP_FAIL;
			node_init(new_node, value);
			node->left = new_node;
			return OP_SUCCESS;
		}
		else return node_add(node->left, value);
	}
	else if(node->value > value)
	{
		if(node->right == NULL)
		{
			new_node = malloc(sizeof(new_node) / sizeof(&new_node));
			if(!new_node) return OP_FAIL;
			node_init(new_node, value);
			node->right = new_node;
			return OP_SUCCESS;
		}
		else return node_add(node->right, value);
	}
	else return OP_FAIL;
}

static int node_contains(struct Node * node, int value)
{
	return OP_SUCCESS;
}


