#include "lists.h"
#include <stdio.h>
/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	size_t counter = 0;
	const listint_t *tortoise = head;
	const listint_t *hare = NULL;

	while (tortoise)
	{
		printf("[%p] %d\n", (void*)tortoise, tortoise->n);
		counter++;

		hare = head;
		while (hare != tortoise)
		{
			if (tortoise == hare)
			{
				printf("-> [%p] %d\n", (void*)tortoise, tortoise - n);
				return(counter);
			}
			hare = hare->next;
		}
		tortoise = tortoise->next;
	}
	return (counter);
}
