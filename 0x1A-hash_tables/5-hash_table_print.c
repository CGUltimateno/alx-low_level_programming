#include "hash_tables.h"
/**
 * hash_table_print - Print all the hash table (include array and list)
 *   @ht: Pointer to the hash table (hash_table_t *)
 * Return: Void.
 */
void hash_table_print(const hash_table_t *ht) {
    unsigned long int i;
    int flag = 0;
    hash_node_t *arr = NULL;
    hash_node_t *node = NULL;

    if (ht == NULL || ht->array == NULL)
    {
        return;
    }
    arr = ht->array;
    printf("{");
    for (; i < ht->size; i++)
    {
        if(ht->array[i] != NULL)
        {
            flag++;
            if (flag == 2)
                printf(", "), flag = 1;
            printf("'%s': '%s'", arr[i]->key, arr[i]->value);
            node = arr[i]->next;
            if(node)
            {
                printf(", ");
                for(; node; node = node->next)
                {
                    printf("'%s': '%s'", node->key, node->value);
                    if(node->next)
                        printf(", ");
                }
            }
        }
    }
    printf("}\n");
}