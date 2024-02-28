#include "binary_trees.h"
#include "0-binary_tree_node.c"

/**
 * _getHeight - A function that measures the height of a binary tree.
 *
 * @tree: Pointer to the root node.
 *
 * Return: Height of the tree. 0, if tree is NULL.
 */
size_t _getHeight(const heap_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_ht = 1 + _getHeight(tree->left);

	if (tree->right)
		right_ht = 1 + _getHeight(tree->right);

	if (left_ht > right_ht)
		return (left_ht);
	return (right_ht);
}


/**
 * _getHeapSize - A function that gets the sum of heights of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t _getHeapSize(const binary_tree_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_ht = 1 + _getHeapSize(tree->left);

	if (tree->right)
		right_ht = 1 + _getHeapSize(tree->right);

	return (left_ht + right_ht);
}


/**
 * preorder_traverse - A function that traverses though a binary tree
 * using pre-order traversal.
 *
 * @tree: Pointer to the root node of the tree.
 * @node: Double pointer to the last node.
 * @height: Height of the tree.
 *
 * Return: Void.
 */
void preorder_traverse(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	preorder_traverse(tree->left, node, height);
	preorder_traverse(tree->right, node, height);
}


/**
 * _makeHeap - A function that maintains the
 * heap property of a Max Binary Heap.
 *
 * @root: Pointer to binary heap.
 */
void _makeHeap(heap_t *root)
{
	heap_t *temp_1, *temp_2;
	int res;

	if (!root)
		return;

	temp_1 = root;

	while (1)
	{
		if (!temp_1->left)
			break;
		if (!temp_1->right)
			temp_2 = temp_1->left;
		else
		{
			if (temp_1->left->n > temp_1->right->n)
				temp_2 = temp_1->left;
			else
				temp_2 = temp_1->right;
		}
		if (temp_1->n > temp_2->n)
			break;
		res = temp_1->n;
		temp_1->n = temp_2->n;
		temp_2->n = res;
		temp_1 = temp_2;
	}
}

/**
 * heap_extract - A function that extracts the
 * root node from a Max Binary Heap.
 *
 * @root: Pointer to the root of the heap.
 *
 * Return: The value of the extracted node.
 **/
int heap_extract(heap_t **root)
{
	heap_t *h_root, *node;
	int res;

	if (!root || !*root)
		return (0);

	h_root = *root;
	res = h_root->n;

	if (!h_root->left && !h_root->right)
	{
		*root = NULL;
		free(h_root);
		return (res);
	}

	preorder_traverse(h_root, &node, _getHeight(h_root));

	h_root->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);

	_makeHeap(h_root);
	*root = h_root;

	return (res);
}
