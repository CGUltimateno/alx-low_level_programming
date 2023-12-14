#include "search_algos.h"
/**
* binary_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located or -1 if value is not present
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
    size_t i, mid = 0;
    if (array == NULL)
        return (-1);
    while (left <= right)
    {
        printf("Searching in array: ");
        for (i = left; i < right; i++)
            printf("%d, ", array[i]);
        printf("%d\n", array[i]);
        mid = (left + right) / 2;
        if (array[mid] == value)
            return (mid);
        else if (array[mid] > value)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located or -1 if value is not present
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t i = 0, bound;

    if (array == NULL || size == 0)
        return (-1);
    if (array[0] != value)
    {
        for (i = 1; i < size && array[i] <= value; i = i * 2)
            printf("Value checked array[%zu] = [%d]\n", i, array[i]);
    }
    bound = i < size ? i : size - 1;
    printf("Value found between indexes [%zu] and [%zu]\n", i / 2, bound);
    return (_binary_search(array, i / 2, bound, value));
}
