#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *table;
unsigned long int i;
table = malloc(sizeof(shash_table_t));
if (table == NULL)
return (NULL);
table->size = size;
table->array = malloc(sizeof(shash_node_t *) * size);
if (table->array == NULL)
{
free(table);
return (NULL);
}
for (i = 0; i < size; i++)
table->array[i] = NULL;
table->shead = NULL;
table->stail = NULL;

return (table);
}
/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int index = 0;
shash_node_t *newNode = NULL, *tmp = NULL;
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
newNode = malloc(sizeof(shash_node_t));
if (newNode == NULL)
return (0);
newNode->key = strdup(key);
newNode->value = strdup(value);
newNode->next = ht->array[index];
ht->array[index] = newNode;
if (ht->shead == NULL)
{
newNode->sprev = NULL;
newNode->snext = NULL;
ht->shead = newNode;
ht->stail = newNode;
}
else if (strcmp(ht->shead->key, key) > 0)
{
newNode->sprev = NULL;
newNode->snext = ht->shead;
ht->shead->sprev = newNode;
ht->shead = newNode;
}
else
{
tmp = ht->shead;
while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
tmp = tmp->snext;
newNode->sprev = tmp;
newNode->snext = tmp->snext;
if (tmp->snext == NULL)
ht->stail = newNode;
else
tmp->snext->sprev = newNode;
tmp->snext = newNode;
}
return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 *  a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *node;
unsigned long int index;
if (ht == NULL || key == NULL || *key == '\0')
return (NULL);
index = key_index((const unsigned char *)key, ht->size);
if (index >= ht->size)
return (NULL);
node = ht->shead;
while (node != NULL && strcmp(node->key, key) != 0)
node = node->snext;
return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */

void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;
if (ht == NULL)
return;
node = ht->shead;
printf("{");
while (node != NULL)
{
printf("'%s': '%s'", node->key, node->value);
node = node->snext;
if (node != NULL)
printf(", ");
}
printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse.
 *  @ht: A pointer to the sorted hash table to print.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;
if (ht == NULL)
return;
node = ht->stail;
printf("{");
while (node != NULL)
{
printf("'%s': '%s'", node->key, node->value);
node = node->sprev;
if (node != NULL)
printf(", ");
}
printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 *  @ht: A pointer to the sorted hash table.
 */

void shash_table_delete(shash_table_t *ht)
{
shash_table_t *head = ht;
shash_node_t *node, *tmp;
if (ht == NULL)
return;


node = ht->shead;
while (node)
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
