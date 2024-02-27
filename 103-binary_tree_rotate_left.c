#include "binary_trees.h"

/**
 * binary_tree_rotate_left - A function that performs a
 * Left-rotatation on a binary tree.
 *
 * @tree: Pointer to the root of the tree.
 *
 * Return: Pointer to the new tree root.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rotate, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	rotate = tree->right;

	temp = rotate->left;

	rotate->left = tree;

	tree->right = temp;

	if (temp != NULL)
		temp->parent = tree;

	temp = tree->parent;

	tree->parent = rotate;

	rotate->parent = temp;

	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = rotate;
		else
			temp->right = rotate;
	}

	return (rotate);
}
