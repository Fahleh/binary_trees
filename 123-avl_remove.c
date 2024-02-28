#include "binary_trees.h"

/**
 * _balanceFactor - A function that measures balance factor of a AVL.
 *
 * @tree: Double pointer to the tree.
 *
 * Return: Void
 */
void _balanceFactor(avl_t **tree)
{
	int bal_fact;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	_balanceFactor(&(*tree)->left);
	_balanceFactor(&(*tree)->right);
	bal_fact = binary_tree_balance((const binary_tree_t *)*tree);

	if (bal_fact > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bal_fact < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}


/**
 * _getHeir - A function that gets the next the node
 * with the min val in the right subtree.
 *
 * @node: Pointer to the tree.
 *
 * Return: The min value of the tree.
 */
int _getHeir(bst_t *node)
{
	int val = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		val = _getHeir(node->left);
		if (val == 0)
		{
			return (node->n);
		}
		return (val);
	}

}


/**
 * _nodeRemove - A function that removes a node depending of its children.
 *
 * @root: Pointer to the node to remove.
 *
 * Return: 0, if it has no children. Value if it does.
 */
int _nodeRemove(bst_t *root)
{
	int val = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		val = _getHeir(root->right);
		root->n = val;
		return (val);
	}
}


/**
 * _bstRemove - A function remove a node from a BST tree.
 *
 * @root: Pointer to the root of the tree.
 * @value: Value to remove.
 * Return: The tree changed.
 */
bst_t *_bstRemove(bst_t *root, int value)
{
	int flag = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		_bstRemove(root->left, value);
	else if (value > root->n)
		_bstRemove(root->right, value);
	else if (value == root->n)
	{
		flag = _nodeRemove(root);
		if (flag != 0)
			_bstRemove(root->right, flag);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - A function that removes a node from a AVL tree.
 *
 * @root: Pointer to the root of the tree.
 * @value: Node with this value to remove.
 *
 * Return: The tree changed.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *avl_root = (avl_t *) _bstRemove((bst_t *) root, value);

	if (avl_root == NULL)
		return (NULL);

	_balanceFactor(&avl_root);

	return (avl_root);
}
