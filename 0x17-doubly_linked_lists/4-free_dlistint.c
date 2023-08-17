#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to the list.
 **/
void free_dlistint(dlistint_t *head)
{
    dlistint_t *a_node;
    dlistint_t *next_node;

    if (head)
    {
        a_node = head;
        next_node = head->next;
        while (next_node)
        {
            free(a_node);
            a_node = next_node;
            next_node = next_node->next;
        }
        free(a_node);
    }
}