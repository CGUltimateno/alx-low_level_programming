#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list.
 * @head: pointer to the list.
 * @index: position of the node to delete.
 * Return: 1 if it succeeded, -1 if it failed.
 **/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *a_node = *head;
	dlistint_t *node_to_delete = *head;
	unsigned int idx;
	unsigned int c = 0;

	/* border case for empty list */
	if (!(*head))
		return (-1);

	/* border case for delete at the beginning */
	if (index == 0)
	{
		*head = node_to_delete->next;
		free(node_to_delete);
		if (*head)
			(*head)->prev = NULL;
		return (1);
	}

	/* search of position to delete */
	idx = index - 1;
	while (a_node && c != idx)
	{
		c++;
		a_node = a_node->next;
	}

	/* general case */
	if (c == idx && a_node)
	{
		node_to_delete = a_node->next;
		if (node_to_delete->next)
		node_to_delete->next->prev = a_node;
		a_node->next = node_to_delete->next;
		free(node_to_delete);
		return (1);
	}

	return (-1);
}