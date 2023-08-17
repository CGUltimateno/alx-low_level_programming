#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node node at a given position
 * in a dlistint_t list.
 * @h: pointer to the list.
 * @idx: position to add the node.
 * @n: data for the new node.
 * Return: the address of the new node, or NULL if it failed
 **/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *a_node = *h, *n_node;
    unsigned int index, cont = 0;

    /* create node */
    n_node = malloc(sizeof(dlistint_t));
    if (n_node == NULL)
        return (NULL);
    n_node->n = n;

    /* border case for insert at the beginning */
    if (idx == 0)
    {
        n_node->prev = NULL;
        n_node->next = *h;
        if (*h)
            (*h)->prev = n_node;
        *h = n_node;
        return (*h);
    }

    /* search of position to insert */
    index = idx - 1;
    while (a_node && cont != index)
    {
        cont++;
        a_node = a_node->next;
    }

    /* general case */
    if (cont == index && a_node)
    {
        n_node->prev = a_node;
        n_node->next = a_node->next;
        if (a_node->next)
            a_node->next->prev = n_node;
        a_node->next = n_node;
        return (n_node);
    }
    free(n_node);
    return (NULL);
}