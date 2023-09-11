#include "hash_tables.h"
/**
 * hash_table_get - Get the value from a hash table
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *node;
    hash_node_t *tmp;

    if (ht == NULL || key == NULL || !ht->array)
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];
    if (node == NULL)
        return (NULL);
    if (strcmp(node->key, key) == 0)
        return (node->value);
    for(tmp = ht->array; tmp != NULL; tmp = tmp->next)
        if (strcmp(tmp->key, key) == 0)
            return (tmp->value);

    return (NULL);
}