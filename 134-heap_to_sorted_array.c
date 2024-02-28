#include "binary_trees.h"

/**
 * _getTreeSize - A function that measures the size of a binary tree.
 *
 * @tree: Pointer to the root of the tree.
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t _getTreeSize(const binary_tree_t *tree)
{
	size_t left_ht = 0, right_ht = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_ht = 1 + _getTreeSize(tree->left);

	if (tree->right)
		right_ht = 1 + _getTreeSize(tree->right);

	return (left_ht + right_ht);
}


/**
 * heap_to_sorted_array - A function that converts a Binary Max Heap
 * to an array of integers sorted in descending order.
 *
 * @heap: Pointer to the root of the heap.
 * @size: Pointer to the size of the array.
 *
 * Return: Pointer to array.
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *arr = NULL;

	if (!heap || !size)
		return (NULL);

	*size = _getTreeSize(heap) + 1;

	arr = malloc(sizeof(int) * (*size));

	if (!arr)
		return (NULL);

	for (i = 0; heap; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}
