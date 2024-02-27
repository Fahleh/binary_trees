#include "binary_trees.h"

/**
 * _isFull - A function that checks if a binary tree is full.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 0 if tree is not full. Else, 1.
 */
int _isFull(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    _isFull(tree->left) == 0 ||
		    _isFull(tree->right) == 0)
			return (0);
	}

	return (1);
}

/**
 * binary_tree_is_full - A function that checks if a binary tree is full.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 0, if tree is not FULL. Else, 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_isFull(tree));
}
