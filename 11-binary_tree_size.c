#include "binary_trees.h"

/**
 * binary_tree_size - A function that measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to.
 *
 * Return: The size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t s = 0;

	if (tree)
	{
		s += 1;
		s += binary_tree_size(tree->left);
		s += binary_tree_size(tree->right);
	}
	return (s);
}
