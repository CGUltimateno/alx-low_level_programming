#include "search_algos.h"
/**
 * rec_search - searches for a value in a sorted array of integers
 * @array: input array
 * @size: size of array
 * @value: value to search for
 * return: index of value or -1 if not found
 */
int rec_search(int *array, size_t size, int value)
{
size_t i, mid;
printf("Searching in array: ");
for (i = 0; i < size; i++)
{
printf("%d", array[i]);
if (i < size - 1)
printf(", ");
else
printf("\n");
}
mid = (size - 1) / 2;
if (array[mid] == value)
{
if (size == 1 || array[mid - 1] < value)
return (mid);
}
if (size == 1)
return (-1);
if (array[mid] < value)
{
return (rec_search(array + mid + 1, size - mid - 1, value) + mid + 1);
}
else
{
return (rec_search(array, mid + 1, value));
}
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: input array
 * @size: size of array
 * @value: value to search for
 * return: index of value or -1 if not found
 */

int advanced_binary(int *array, size_t size, int value)
{
if (size == 0 || array == NULL)
return (-1);

return (rec_search(array, size, value));
}
