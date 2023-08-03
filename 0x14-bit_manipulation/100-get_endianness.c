#include "main.h"
/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
    int x = 1;
    if ((x >> 31) == 1){
        return (0);
    }
    else{
        return (1);
    }
}