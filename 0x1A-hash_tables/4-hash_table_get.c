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
    hash_node_t *cnode;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    if (index >= ht->size)
        return (NULL);

    cnode = ht->array[index];
    while (cnode && strcmp(cnode->key, key) != 0)
        cnode = cnode->next;

    return ((cnode == NULL) ? NULL : cnode->value);
}