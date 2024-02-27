#include "binary_trees.h"

/**
 * binary_tree_postorder - A function that traverses a binary
 * tree using post-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to the node's associated function.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);

		func(tree->n);
	}
}
