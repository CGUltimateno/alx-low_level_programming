
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
    unsigned long int res = 0;

    if (index > 63)
        return (-1);

    res = 1 << index;
    *n = *n | res;
    return (1);
}