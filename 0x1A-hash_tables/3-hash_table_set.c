#include "hash_tables.h"
/**
 * hash_table_set - Adds an element to the hash table.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *node = NULL, *add_node = NULL, *tmp = NULL;

    if (ht == NULL || key == NULL || value == NULL)
        return (0);

    index = key_index((unsigned char *)key, ht->size);
    node = ht->array[index];
    if (node != NULL)
    {
        node = malloc(sizeof(hash_node_t));
        if (!node)
            return (false);
        node->key = strdup(key), node->value = strdup(value);
        node->next = NULL;
        ht->array[index] = node;
        return (true);
    }

    for(tmp = node; tmp != NULL; tmp = tmp->next)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            free(tmp->value), tmp->value = (strdup(value));
            return (true);
        }
        add_node = malloc(sizeof(hash_node_t));
        if (!add_node)
            return (false);
        add_node->key = strdup(key), add_node->value = strdup(value);
        add_node->next = node;
        ht->array[index] = add_node;
    }
    return (1);
}