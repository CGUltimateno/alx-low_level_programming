#include "hash_tables.h"
/**
 * free_list - Free a list.
 *  @head: Pointer to the head of a linked list
 *
 * Return: Void.
 */
void free_list(hash_node_t *head)
{
    hash_node_t *tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }
}
/**
 * hash_table_delete - Deletes a hash table
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;

    for (i = 0; i < ht->size; i++)
    {
        if (ht->array[i])
            free_list(ht->array[i]);
    }
    free(ht->array);
    free(ht);
}