#include "binary_trees.h"

/**
 * binary_tree_height - A function that measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the true or 0 if NULL. If tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t west = 0, east = 0;

		if (tree->left)
			west = 1 + binary_tree_height(tree->left);
		else
			west = 0;

		if (tree->right)
			east = 1 + binary_tree_height(tree->right);
		else
			east = 0;

		return ((west > east) ? west : east);
	}

	return (0);
}
