#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"


/**
 * _maxCheck - A function that checks a binary tree for max values.
 *
 * @tree: pointer to the root node.
 *
 * Return: 1, if all nodes are max. 0 in other cases
 **/

int _maxCheck(const binary_tree_t *tree)
{
	int flag1 = 1, flag2 = 1;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);

		flag1 = _maxCheck(tree->left);
	}

	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);

		flag2 = _maxCheck(tree->right);
	}

	return (flag1 && flag2);
}



/**
 * binary_tree_is_heap - A function that checks if a binary tree is heap.
 *
 * @tree: pointer to the node
 * Return: 1, if tree is a valid Max Binary Heap. 0 otherwise.
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int temp;

	if (!tree)
		return (0);

	temp = binary_tree_is_complete(tree);

	if (!temp)
		return (0);

	return (_maxCheck(tree));
}
