#include "hash_tables.h"
/**
 * hash_table_create - Create a new hash table.
 */

hash_table_t *hash_table_create(unsigned long int index)
{
    unsigned long int i;
    hash_table_t *new_table = malloc(sizeof(hash_table_t));
    if (new_table == NULL)
        return (NULL);

    new_table->size = index;
    new_table->array = malloc(sizeof(hash_node_t *) * index);
    if (new_table->array == NULL)
        return (NULL);

    for (i = 0; i < index; i++)
        new_table->array[i] = NULL;

    return (new_table);
}