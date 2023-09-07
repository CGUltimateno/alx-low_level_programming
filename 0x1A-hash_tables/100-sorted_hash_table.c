#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht = NULL;
    unsigned long int i = 0;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}
/**
 * shash_table_set - Adds an element to a sorted hash table.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index = 0;
    shash_node_t *new_node = NULL, *tmp = NULL;

    if (ht == NULL || key == NULL || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    tmp = ht->array[index];

    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            free(tmp->value);
            tmp->value = strdup(value);
            return (1);
        }
        tmp = tmp->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    if (ht->shead == NULL)
    {
        new_node->sprev = NULL;
        new_node->snext = NULL;
        ht->shead = new_node;
        ht->stail = new_node;
    }
    else if (strcmp(ht->shead->key, key) > 0)
    {
        new_node->sprev = NULL;
        new_node->snext = ht->shead;
        ht->shead->sprev = new_node;
        ht->shead = new_node;
    }
    else
    {
        tmp = ht->shead;
        while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
            tmp = tmp->snext;

        new_node->sprev = tmp;
        new_node->snext = tmp->snext;
        if (tmp->snext == NULL)
            ht->stail = new_node;
        else
            tmp->snext->sprev = new_node;
        tmp->snext = new_node;
    }

    return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index = 0;
    shash_node_t *tmp = NULL;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    tmp = ht->array[index];

    while (tmp != NULL)
    {
        if (strcmp(tmp->key, key) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 */

void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *tmp = NULL;
    int flag = 0;

    if (ht == NULL)
        return;

    tmp = ht->shead;
    printf("{");
    while (tmp != NULL)
    {
        if (flag == 1)
            printf(", ");
        printf("'%s': '%s'", tmp->key, tmp->value);
        flag = 1;
        tmp = tmp->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *tmp = NULL;
    int flag = 0;

    if (ht == NULL)
        return;

    tmp = ht->stail;
    printf("{");
    while (tmp != NULL)
    {
        printf("'%s': '%s'", tmp->key, tmp->value);
        tmp = tmp->sprev;
        if (tmp != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 */

void shash_table_delete(shash_table_t *ht)
{
    shash_table_t *head = ht;
    shash_node_t *node, *tmp;

    node = head->shead;
    while (node != NULL)
    {
        tmp = node->snext;
        free(node->key);
        free(node->value);
        free(node);
        node = tmp;
    }
    free(head->array);
    free(head);
}