#include "binary_trees.h"

/**
 * binary_tree_leaves - iA function thst counts the leaves in a binary tree.
 *
 * @tree: Pointer to the root of the tree.
 *
 * Return: The number of leaves in the tree or 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf_count = 0;

	if (tree)
	{
		leaf_count += (!tree->left && !tree->right) ? 1 : 0;
		leaf_count += binary_tree_leaves(tree->left);
		leaf_count += binary_tree_leaves(tree->right);
	}

	return (leaf_count);
}
