#include "binary_trees.h"

/**
 * _bstValidate - A function that checks if a binary tree
 * is a valid binary search tree.
 *
 * @tree: Pointer to the root of the tree.
 * @low: Value of the smallest node visited.
 * @high: Value of the largest node visited.
 *
 * Return: 1, if the tree is a valid BST. Else, 0.
 */
int _bstValidate(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);

		return (_bstValidate(tree->left, low, tree->n - 1) &&
			_bstValidate(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_bst - A function that checks if a
 * binary tree is a valid binary search tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1, if tree is a valid BST. Else, 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_bstValidate(tree, INT_MIN, INT_MAX));
}
