#include "binary_trees.h"

/**
 * _isLeaf - A function that checks if a node is a leaf of a binary tree.
 *
 * @node: Pointer to the node to check.
 *
 * Return: 1, if the node is a leaf. Else, 0.
 */
unsigned char _isLeaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}


/**
 * _checkDepth - A function that checks the depth of a
 * given node in a binary tree.
 *
 * @tree: Pointer to the node to check.
 *
 * Return: The depth of node or 0 if tree is NULL.
 */
size_t _checkDepth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + _checkDepth(tree->parent) : 0);
}


/**
 * _getLeaf - A function that gets the leaf of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: A pointer to the leaf.
 */
const binary_tree_t *_getLeaf(const binary_tree_t *tree)
{
	if (_isLeaf(tree) == 1)
		return (tree);
	return (tree->left ? _getLeaf(tree->left) : _getLeaf(tree->right));
}


/**
 * _isPerfect - A function that checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the tree.
 * @depth: The depth of a leaf in the tree.
 * @level: Level of the current node.
 *
 * Return: 1, if the tree is perfect. Else, 0.
 */
int _isPerfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (_isLeaf(tree))
		return (level == depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (_isPerfect(tree->left, depth, level + 1) &&
		_isPerfect(tree->right, depth, level + 1));
}


/**
 * binary_tree_is_perfect - A function that checks if a
 * binary tree is perfect.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 0, If tree is not perfect or NULL. Else, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_isPerfect(tree, _checkDepth(_getLeaf(tree)), 0));
}
