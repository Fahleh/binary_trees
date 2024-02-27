#include "binary_trees.h"

/**
 * binary_tree_height - A function that measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree. 0, if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t west = 0, east = 0;

		west = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		east = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((west > east) ? west : east);
	}
	return (0);
}


/**
 * binary_tree_balance - A function that measures the
 * balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The balance factor. 0, if the tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left)
				- binary_tree_height(tree->right));

	return (0);
}
