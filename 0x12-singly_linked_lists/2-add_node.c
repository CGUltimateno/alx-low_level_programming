#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node
 * @head: double pointer
 * @str: new string
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t* add_node(list_t** head, const char* str)
{
	list_t* list;
	unsigned int strlen = 0;

	while (str[strlen])
		strlen++;

	list = malloc(sizeof(list_t));
	if (!list)
		return (NULL);

	list->str = strdup(str);
	list->len = strlen;
	list->next = (*head);
	(*head) = list;

	return (*head);
}
