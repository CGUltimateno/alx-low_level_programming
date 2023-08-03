#include "main.h"

/**
 * set_bit - sets a bit at a given index to 1
 * @n: pointer to the number to change
 * @index: index of bit 1
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    unsigned long int x;

    if (index > (sizeof(unsigned long int) * 8 - 1))
        return (-1);
    x = 1 << index;
    *n = *n | x;

    return (1);
}