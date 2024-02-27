#include "binary_trees.h"

/**
 * bst_insert - A function that inserts a value in a Binary Search Tree.
 *
 * @tree: A double pointer to the root of the BST.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *existing, *new_node;

	if (tree != NULL)
	{
		existing = *tree;

		if (existing == NULL)
		{
			new_node = binary_tree_node(existing, value);
			if (new_node == NULL)
				return (NULL);

			return (*tree = new_node);
		}

		if (value < existing->n)
		{
			if (existing->left != NULL)
				return (bst_insert(&existing->left, value));

			new_node = binary_tree_node(existing, value);

			if (new_node == NULL)
				return (NULL);

			return (existing->left = new_node);
		}

		if (value > existing->n)
		{
			if (existing->right != NULL)
				return (bst_insert(&existing->right, value));

			new_node = binary_tree_node(existing, value);
			if (new_node == NULL)
				return (NULL);
			return (existing->right = new_node);
		}
	}
	return (NULL);
}
