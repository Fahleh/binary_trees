#include "binary_trees.h"

/**
 * _getSuccessor - A function that returns the
 * minimum value of a binary search tree.
 *
 * @root: A pointer to the root node.
 *
 * Return: The minimum value in the tree.
 */
bst_t *_getSuccessor(bst_t *root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}

	return (root);
}



/**
 * _bstDelete - A function that deletes a node from a binary search tree.
 *
 * @root: Pointer to the root node.
 * @node: Pointer to the node to delete.
 *
 * Return: A pointer to the new root node.
 */
bst_t *_bstDelete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *heir = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;

		if (node->right != NULL)
			node->right->parent = parent;

		free(node);

		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;

		if (node->left != NULL)
			node->left->parent = parent;

		free(node);

		return (parent == NULL ? node->left : root);
	}

	heir = _getSuccessor(node->right);
	node->n = heir->n;

	return (_bstDelete(root, heir));
}


/**
 * _recursiveRemove - A function that recursively removes a node from a
 * binary search tree.
 *
 * @root: Pointer to the root node of the BST.
 * @node: A pointer to the current BST node.
 * @value: The value to remove.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *_recursiveRemove(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (_bstDelete(root, node));

		if (node->n > value)
			return (_recursiveRemove(root, node->left, value));

		return (_recursiveRemove(root, node->right, value));
	}

	return (NULL);
}



/**
 * bst_remove - A function that removes a node from a binary search tree.
 *
 * @root: Pointer to the root node.
 * @value: Value to remove in the BST.
 *
 * Return: A pointer to the new root node.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (_recursiveRemove(root, root, value));
}
