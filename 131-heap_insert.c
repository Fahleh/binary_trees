#include "binary_trees.h"


/**
 * _getSize - A function that measures the size of a binary tree.
 *
 * @tree: Pointer to the root of the tree.
 *
 * Return: Size of the tree. 0, if tree is NULL.
 */
size_t _getSize(const binary_tree_t *tree)
{
        if (!tree)
                return (0);

        return (_getSize(tree->left) + _getSize(tree->right) + 1);
}


/**
 * heap_insert - A function that inserts a value in Max Binary Heap.
 *
 * @root: Double pointer to the root node of the heat.
 * @value: Value to store in the node.
 *
 * Return: Pointer to the created node. NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *swap;
	int s, temp, leaves, lev, sub_lev, bit;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	s = _getSize(tree);
	leaves = s;
	for (lev = 0, sub_lev = 1; leaves >= sub_lev; sub_lev *= 2, lev++)
		leaves -= sub_lev;

	for (bit = 1 << (lev - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	/*
	 * Traverse tree to first empty slot based on the binary
	 * representation of the number of leaves.
	 * Example -
	 * If there are 12 nodes in a complete tree, there are 5 leaves on
	 * the 4th tier of the tree. 5 is 101 in binary. 1 corresponds to
	 * right, 0 to left.
	 * The first empty node is 101 == RLR, *root->right->left->right
	 */

	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	swap = new_node;
	for (; swap->parent && (swap->n > swap->parent->n); swap = swap->parent)
	{
		temp = swap->n;
		swap->n = swap->parent->n;
		swap->parent->n = temp;
		new_node = new_node->parent;
	}

	return (new_node);
}
