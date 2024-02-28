#include "binary_trees.h"


/**
 * _getHeight - A function that measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 0, if tree is NULL. Else, height.
 */
size_t _getHeight(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left = 0, right = 0;

		left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return ((left > right) ? left : right);
	}

	return (0);
}


/**
 * _checkBalance - A functtion that measures the
 * balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 0, if tree is NULL. Else, balance factor.
 */
int _checkBalance(const binary_tree_t *tree)
{
	return (tree != NULL ? _getHeight(tree->left) -
			_getHeight(tree->right) : 0);
}


/**
 * _avlInsert - A function that inserts a value into an AVL tree.
 *
 * @tree: Double pointer to the root node.
 * @parent: Parent node of the current working node.
 * @new: Double pointer to the new node.
 * @value: Value to insert into the tree.
 *
 * Return: A pointer to the new root, or NULL.
 */
avl_t *_avlInsert(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int bal_fact;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = _avlInsert(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = _avlInsert(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bal_fact = _checkBalance(*tree);
	if (bal_fact > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bal_fact < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bal_fact > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bal_fact < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}


/**
 * avl_insert - A function that inserts a value into an AVL tree.
 *
 * @tree: Double pointer to the root node.
 * @value: Value to insert into the AVL tree.
 *
 * Return: Pointer to the inserted node, or NULL.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	_avlInsert(tree, *tree, &new_node, value);

	return (new_node);
}
