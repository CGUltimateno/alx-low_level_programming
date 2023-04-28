#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a list node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the list node
 *
 * Return: address of the list element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *list, *tmp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	list = malloc(sizeof(list_t));
	if (list == NULL)
		return (NULL);

	list->str = strdup(str);
	list->len = len;
	list->next = NULL;

	if (*head == NULL)
	{
		*head = list;
		return (list);
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = list;

	return (list);
}
