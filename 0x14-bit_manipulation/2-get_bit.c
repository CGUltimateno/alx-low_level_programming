#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @n: number to search
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
    unsigned long int x, res;
    if(index > (sizeof(unsigned long int) * 8 -1))
        return(-1);
    x = 1 << index;
    res = n & x;
    if(res == x)
        return (1);

    return (0);
}
