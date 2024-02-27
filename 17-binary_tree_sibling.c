#include "binary_trees.h"

/**
 * binary_tree_sibling - A function that finds the sibling of a
 * node in a binary tree.
 *
 * @node: Pointer to the node.
 *
 * Return: A pointer to the sibling. NULL, If no sibling or node is NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
