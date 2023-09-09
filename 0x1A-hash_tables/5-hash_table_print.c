#include "hash_tables.h"
/**
 * hash_table_print - Print all the hash table (include array and list)
 *   @ht: Pointer to the hash table (hash_table_t *)
 * Return: Void.
 */
void hash_table_print(const hash_table_t *ht) {
    hash_node_t *currentNode;
    unsigned long int index;
    unsigned char commaNeeded = 0;

    if (ht == NULL)
        return;

    printf("{");
    for (index = 0; index < ht->size; index++) {
        if (ht->array[index] != NULL) {
            if (commaNeeded == 1)
                printf(", ");

            currentNode = ht->array[index];
            while (currentNode != NULL) {
                printf("'%s': '%s'", currentNode->key, currentNode->value);
                currentNode = currentNode->next;
                if (currentNode != NULL)
                    printf(", ");
            }
            commaNeeded = 1;
        }
    }
    printf("}\n");
}