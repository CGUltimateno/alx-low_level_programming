#include "search_algos.h"

/**
 * _binary_search - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @low: lowest index of the subarray
 * @high: highest index of the subarray
 * @value: value to search for
 *
 * Return: first index where value is located or -1 if value is not present
 */
int linear_search(int *array, size_t size, int value)
{
size_t index = 0;

if (array == NULL)
return (-1);

while (index < size)
{
printf("Value checked array[%ld] = [%d]\n", index, array[index]);
if (array[index] == value)
return (index);

index++;
}
return (-1);
}
