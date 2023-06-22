#include "function_pointers.h"
#include <stdio.h>
/**
 * array_iterator - prints each array elem on a newl
 * @array: array
 * @size: how many elem to print
 * @action: pointer to print in regular or hex
 * Return: void
 */
void array_iterator(int *a, size_t size, void (*x)(int))
{
	unsigned int i;

	if (a == NULL || x == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		x(a[i]);
	}
}
