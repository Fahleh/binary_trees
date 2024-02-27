#include "binary_trees.h"

/**
 * binary_tree_rotate_right - A function that performs a
 * right-rotation on a binary tree.
 *
 * @tree: Pointer to the root of the tree.
 *
 * Return: Pointer to the new root node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rotate, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	rotate = tree->left;

	temp = rotate->right;

	rotate->right = tree;

	tree->left = temp;

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
