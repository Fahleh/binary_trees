#include "binary_trees.h"

/**
 * bst_search - A function that searches for a value in a binary search tree.
 *
 * @tree: Pointer to the root node.
 * @value: Value to search for in the BST.
 *
 * Return: Pointer to the relevant node. NULL, 
 * if the tree is NULL or the value is not found, NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);

		if (tree->n > value)
			return (bst_search(tree->left, value));

		return (bst_search(tree->right, value));
	}

	return (NULL);
}
