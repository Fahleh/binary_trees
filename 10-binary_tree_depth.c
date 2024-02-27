#include "binary_trees.h"

/**
 * binary_tree_depth - A function that measures the depth
 * of a node in a binary tree.
 *
 * @tree: A pointer to the node to measure.
 *
 * Return: The depth of the node or 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}
