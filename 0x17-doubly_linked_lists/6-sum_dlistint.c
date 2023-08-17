#include "lists.h"

/**
 * sum_dlistint - returns the res of all the data (n) of a dlistint_t list.
 * @head: pointer to the list.
 * Return: res of all data in the list, 0 if the lost is empty.
 **/
int sum_dlistint(dlistint_t *head)
{
    dlistint_t *node = head;
    int res = 0;

    while (node)
    {
        res += node->n;
        node = node->next;
    }

    return (res);
}