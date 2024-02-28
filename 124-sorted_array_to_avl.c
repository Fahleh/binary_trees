#include "binary_trees.h"

/**
 * _generateTree - A functtion that creates an AVL tree.
 *
 * @node: Pointer to an AVL node.
 * @arr: Array of integers.
 * @size: size of the array.
 * @mode: 1 for adding on the left. 2 to for adding on the right.
 *
 * Return: Void.
 */
void _generateTree(avl_t **node, int *arr, size_t size, int mode)
{
	size_t mid;

	if (size == 0)
		return;

	mid = (size / 2);
	mid = (size % 2 == 0) ? mid - 1 : mid;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, arr[mid]);
		_generateTree(&((*node)->left), arr, mid, 1);
		_generateTree(&((*node)->left), arr + mid + 1, (size - 1 - mid), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, arr[mid]);
		_generateTree(&((*node)->right), arr, mid, 1);
		_generateTree(&((*node)->right), arr + mid + 1, (size - 1 - mid), 2);
	}
}

/**
 * sorted_array_to_avl - A function that builds an AVL tree from an array.
 *
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Return: Pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t mid;

	tree = NULL;

	if (size == 0)
		return (NULL);

	mid = (size / 2);

	mid = (size % 2 == 0) ? mid - 1 : mid;

	tree = binary_tree_node(tree, array[mid]);

	_generateTree(&tree, array, mid, 1);
	_generateTree(&tree, array + mid + 1, (size - 1 - mid), 2);

	return (tree);
}
