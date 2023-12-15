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
size_t i = 0;
size_t x = size / 2;
if (size == 0)
return (-1);
printf("Searching in array: ");
for (i = 0; i < size; i++)
{
printf("%s %d", (i == 0) ? ":" : ",", array[i]);
}
printf("\n");
if (x && size % 2 == 0)
x -= 1;
if (array[x] == value)
return (x);
else if (array[x] > value)
return (rec_search(array, x + 1, value));
else
{
x++;
return (x + rec_search(array + x, size - x, value));
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
int i;
i = rec_search(array, size, value);

if (i >= 0 && array[i] != value)
return (-1);

return (i);
}