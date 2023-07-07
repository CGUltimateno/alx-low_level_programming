#include "main.h"
/**
 * _power - calculate (base and power)
 * @base: base of the exponet
 * @pow: power of the exponet
 * Return: value of base and power
 */
unsigned long int _power(unsigned int base, unsigned int pow){
    unsigned long int n;
    unsigned int x;

    n = 1;
    for (x = 1; x <= pow; x++)
        n *= base;
    return (n);
}

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n){
    unsigned long int x, res;
    char f = 0;

    x = _power(2, sizeof(unsigned long int) * 8 - 1);
    while (x != 0){
        res = n & x;
        if(res == x){
            f = 1;
            _putchar('1');
        }
        else if(f == 1 || x == 1){
            _putchar('0');
        }
        x >>= 1;
    }
}
