#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t* insert_nodeint_at_index(listint_t** head, unsigned int idx, int n)
{
	unsigned int x;
	listint_t *node;
	listint_t *tmp = *head;

	new = malloc(sizeof(listint_t));
	if (!node || !head)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (idx == 0)
	{
		node->next = *head;
		*head = node;
		return (node);
	}

	for (x = 0; tmp && x < idx; x++)
	{
		if (x == idx - 1)
		{
			node->next = tmp->next;
			tmp->next = node;
			return (node);
		}
		else
			tmp = tmp->next;
	}

	return (NULL);
}
