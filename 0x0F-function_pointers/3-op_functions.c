#include "3-calc.h"

int lol_add(int a, int b);
int lol_sub(int a, int b);
int lol_mul(int a, int b);
int lol_div(int a, int b);
int lol_mod(int a, int b);

/**
 * lol_add - Returns the sum of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The sum of a and b.
 */
int lol_add(int a, int b)
{
	return (a + b);
}
/**
 * lol_sub - Returns the difference of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The difference of a and b.
 */
int lol_sub(int a, int b)
{
	return (a - b);
}
/**
 * lol_mul - Returns the product of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The product of a and b.
 */
int lol_mul(int a, int b)
{
	return (a * b);
}
/**
 * lol_div - Returns the division of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The quotient of a and b.
 */
int lol_div(int a, int b)
{
	return (a / b);
}
/**
 * lol_mod - Returns the remainder of the division of two numbers.
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The remainder of the division of a by b.
 */
int lol_mod(int a, int b)
{
	return (a % b);
}
