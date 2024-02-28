#include "binary_trees.h"

/**
 * array_to_heap - A function that builds a Max Binary Heap tree from an array.
 *
 * @array: Pointer to the first element of the array.
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the created Binary Heap,
 * or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	unsigned int i;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
