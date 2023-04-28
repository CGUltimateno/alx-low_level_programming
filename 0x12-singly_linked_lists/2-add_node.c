#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * _strlen - function that returns the length of a string.
 * @s : s is a character
 * Return: value is i
 */

int _strlen(const char* s) {
	int i = 0;
	while (s[i] != '\0') { i++; }
	return(i);
}
/**
 * add_node - adds a new node
 * @head: double pointer
 * @str: new string
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *list;
	list = malloc(sizeof(list_t));

	if (list == NULL)
		return (NULL);
	list->str = strdup(str);
	list->len = _strlen(str);
	list->next = *head;
	*head = list;
	return (list);
}
