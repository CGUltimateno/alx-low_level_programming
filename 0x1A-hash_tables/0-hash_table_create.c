#include "hash_tables.h"
/**
 * hash_table_create - Create a new hash table.
 *  * @size: The size of  array.
 *
 * Return: If there's an error - NULL.
 *         Otherwise - a pointer to a new hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *y;
unsigned long int i;

y = malloc(sizeof(hash_table_t));
if (y == NULL)
    return (NULL);

y->size = size;
y->array = malloc(sizeof(hash_node_t *) * size);
if (y->array == NULL)
    return (NULL);
for (i = 0; i < size; i++)
    y->array[i] = NULL;

return (y);
}
