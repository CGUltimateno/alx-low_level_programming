#include "hash_tables.h"
/**
 * key_index - Gives you the index of a key.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int hash;

    hash = hash_djb2(key);

    return (hash % size);
}