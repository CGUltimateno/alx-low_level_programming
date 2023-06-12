#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **i;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);

	i = malloc(sizeof(int *) * height);

	if (i == NULL)
		return (NULL);

	for (x = 0; x < height; x++)
	{
		i[x] = malloc(sizeof(int) * width);

		if (i[x] == NULL)
		{
			for (; x >= 0; x--)
				free(i[x]);

			free(i);
			return (NULL);
		}
	}

	for (x = 0; x < height; x++)
	{
		for (y = 0; y < width; y++)
			i[x][y] = 0;
	}

	return (i);
}
