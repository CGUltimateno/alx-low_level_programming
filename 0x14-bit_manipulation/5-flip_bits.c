#include "main.h"
/**
 * flip_bits - number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int diff, res;
    unsigned int x = 0, i;

    res = 1;
    diff = n ^ m;
    for (i = 0; i < (sizeof(unsigned long int) * 8); i++)
    {
        if (res == (diff & res))
            x++;
        res <<= 1;
    }

    return (x);
}