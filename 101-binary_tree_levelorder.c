#include "binary_trees.h"

/**
 * _createNode - A function that creates a new level-order node.
 *
 * @node: A binary tree node.
 *
 * Return: Pointer to the new node or NULL.
 */
levelorder_queue_t *_createNode(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}


/**
 * _freeQ - A function that frees a level-order queue.
 *
 * @head: Pointer to the start of the queue.
 */
void _freeQ(levelorder_queue_t *head)
{
	levelorder_queue_t *new_node;

	while (head != NULL)
	{
		new_node = head->next;
		free(head);
		head = new_node;
	}
}

/**
 * _push_to_queue - A function that pushes the children of a binary tree node
 * into a level-order queue.
 *
 * @node: The node to push.
 * @head: Double pointer to the head of the queue.
 * @tail: Double pointer to the tail of the queue.
 * @func: Pointer to the function to call on @node.
 *
 * Return: Void.
 */
void _push_to_queue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_node;

	func(node->n);

	if (node->left != NULL)
	{
		new_node = _createNode(node->left);

		if (new_node == NULL)
		{
			_freeQ(head);
			exit(1);
		}

		(*tail)->next = new_node;
		*tail = new_node;
	}

	if (node->right != NULL)
	{
		new_node = _createNode(node->right);

		if (new_node == NULL)
		{
			_freeQ(head);
			exit(1);
		}

		(*tail)->next = new_node;
		*tail = new_node;
	}
}


/**
 * _unshift - A function that deletes the head of a level-order queue.
 *
 * @head: Double pointer to the head of the queue.
 *
 * Return: Void.
 */
void _unshift(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}


/**
 * binary_tree_levelorder - A function that Traverses a binary tree using
 * level-order traversal.
 *
 * @tree: Pointer to the root of the tree.
 * @func: A pointer to the associated function for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = _createNode((binary_tree_t *)tree);

	if (head == NULL)
		return;

	while (head != NULL)
	{
		_push_to_queue(head->node, head, &tail, func);
		_unshift(&head);
	}
}
