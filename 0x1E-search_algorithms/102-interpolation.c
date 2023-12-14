#include "search_algos.h"
#include <stdio.h>
#include <math.h>
/**
 * interpolation_search - searches for a value in a sorted array
 * of integers using the Interpolation search algorithm
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 * Return: index where value is located or -1
 */
int interpolation_search(int *array, size_t size, int value)
{
int low = 0, high = size - 1, pos;
if (!array || !size)
return (-1);
while (low <= high)
{
pos = low + (((double)(high - low) / (array[high] - array[low])) *
(value - array[low]));
if (pos > (int)size - 1)
{
printf("Value checked array[%d] is out of range\n", pos);
break;
}
printf("Value checked array[%d] = [%d]\n", pos, array[pos]);
if (array[pos] == value)
return (pos);
if (array[pos] < value)
low = pos + 1;
else
high = pos - 1;
}
return (-1);
}