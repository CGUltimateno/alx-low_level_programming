#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int res;
    int length, binary;

    if (!b)
        return (0);

    res = 0;

    for (length = 0; b[length] != '\0'; length++)
        ;

    for (length--, binary = 1; length >= 0; length--, binary *= 2)
    {
        if (b[length] != '0' && b[length] != '1')
        {
            return (0);
        }

        if (b[length] & 1)
        {
            res += binary;
        }
    }
    return (res);
}