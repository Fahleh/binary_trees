#include "binary_trees.h"

/**
 * _createNode - A function that creates a new leve-lorder node.
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
