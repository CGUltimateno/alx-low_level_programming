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
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	if (idx == 0)
	{
		listint_t *new = malloc(sizeof(listint_t));
		if (new == NULL)
			return(NULL);

		new->n = n;
		new->next = *head;
		*head = new;

		return(new);
	}
	if (*head == NULL)
		return(NULL);

	return(insert_nodeint_at_index(&(*head)->next, idx - 1, n));
}
