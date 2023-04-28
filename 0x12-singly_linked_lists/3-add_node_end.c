#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * _strlen - finds the length of a string
 * @str: string to find the length of
 *
 * Return: length of string
 */
unsigned int strlen(char* str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}
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
	if (head == NULL || str == NULL) {
		return(NULL);
	}
	list = malloc(sizeof(list_t));
	if (list == NULL)
		return (NULL);

	list->str = strdup(str);
	if (list - str == NULL) {
		free(list);
		return(NULL);
	}
	list->len = strlen(str);
	list->next = NULL;

	if (*head == NULL)
	{
		*head = list;
	}
	else {
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = list;
	}

	return (list);
}
