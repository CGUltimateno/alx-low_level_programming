#include "search_algos.h"

/**
* binary_search - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located or -1 if value is not present
 */
int _binary_search(int *array, int low, int high, int value)
{
int mid, index;
while (low <= high)
{
printf("Searching in array: ");
for (index = low; index < high; index++)
printf("%d, ", array[index]);
printf("%d\n", array[index]);
mid = (low + high) / 2;
if (array[mid] == value)
return (mid);
else if (array[mid] < value)
low = mid + 1;
else
high = mid - 1;
}
return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located or -1 if value is not present
 */
int exponential_search(int *array, size_t size, int value)
{
size_t i = 0, bound = 1;
if (!array)
return (-1);
while (bound < size)
{
printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
if (array[bound] >= value)
break;
i = bound;
bound *= 2;
}
printf("Value found between indexes [%lu] and [%lu]\n", bound / 2,
(bound > size - 1 ? size - 1 : bound));
i = bound / 2;
bound = (bound > size - 1 ? size - 1 : bound);
return (_binary_search(array, i, bound, value));
}
