#include "binary_trees.h"

/*size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);
*/

/**
 * _getHeight - A function that measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 0, if tree is NULL. Else, height.
 */
size_t _getHeight(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0, right = 0;

		left = tree->left ? 1 + _getHeight(tree->left) : 1;
		right = tree->right ? 1 + _getHeight(tree->right) : 1;

		return ((left > right) ? left : right);
	}

	return (0);
}


/**
 * _avlValidate - A function that checks if a binary tree is a valid AVL tree.
 *
 * @tree: Pointer to the root node.
 * @low: Value of the smallest node visited.
 * @high: Value of the largest node visited.
 *
 * Return: 1, if the tree is a valid AVL tree. Else, 0.
 */
int _avlValidate(const binary_tree_t *tree, int low, int high)
{
	size_t l_height, r_height, variance;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);

		l_height = _getHeight(tree->left);
		r_height = _getHeight(tree->right);
		variance = l_height > r_height ? l_height - r_height
			: r_height - l_height;

		if (variance > 1)
			return (0);

		return (_avlValidate(tree->left, low, tree->n - 1) &&
			_avlValidate(tree->right, tree->n + 1, high));
	}

	return (1);
}


/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (_avlValidate(tree, INT_MIN, INT_MAX));
}
