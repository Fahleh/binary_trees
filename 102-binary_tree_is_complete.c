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
 * _push_to_queue - A function that pushes a node to the
 * back of a level-order queue.
 *
 * @node: The node to push.
 * @head: Double pointer to the head of the queue.
 * @tail: Double pointer to the tail of the queue.
 *
 * Return: Void.
 */
void _push_to_queue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node;

	new_node = _createNode(node);

	if (new_node == NULL)
	{
		_freeQ(head);
		exit(1);
	}

	(*tail)->next = new_node;
	*tail = new_node;
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
 * binary_tree_is_complete - A function that checks
 * if a binary tree is complete.
 *
 * @tree: Pointer to the root of the tree.
 *
 * Return: 0, If the tree is NULL or incomplete. Else, 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char sign = 0;

	if (tree == NULL)
		return (0);

	head = tail = _createNode((binary_tree_t *)tree);

	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (sign == 1)
			{
				_freeQ(head);
				return (0);
			}
			_push_to_queue(head->node->left, head, &tail);
		}
		else
			sign = 1;
		if (head->node->right != NULL)
		{
			if (sign == 1)
			{
				_freeQ(head);
				return (0);
			}
			_push_to_queue(head->node->right, head, &tail);
		}
		else
			sign = 1;
		_unshift(&head);
	}

	return (1);
}
