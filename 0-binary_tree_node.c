#include "binary_trees.h"

/**
 * binary_tree_node - A function that creates a binary tree node.
 *
 * @parent: Pointer to the parent of the created node.
 * @value: Value of the node.
 *
 * Return: A pointer to the new node, or NULL if error occurs.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
