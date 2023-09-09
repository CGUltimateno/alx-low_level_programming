#include "hash_tables.h"
/**
 * hash_table_get - Get the value from a hash table
 * @ht: Pointer to the hash table (hash_table_t *)
 * Return: Void.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    hash_node_t *currentNode;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    if (index >= ht->size)
        return (NULL);

    currentNode = ht->array[index];
    while (currentNode && strcmp(currentNode->key, key) != 0)
        currentNode = currentNode->next;

    return ((currentNode == NULL) ? NULL : currentNode->value);
}