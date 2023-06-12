#include "main.h"
#include <stdlib.h>
/**
 * argstostr - main entry
 * @x: int input
 * @av: double pointer array
 * Return: 0
 */
char *argstostr(int x, char **av)
{
	int i, n, r = 0, l = 0;
	char *string;

	if (x == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < x; i++)
	{
		for (n = 0; av[i][n]; n++)
			l++;
	}
	l += x;

	string = malloc(sizeof(char) * l + 1);
	if (string == NULL)
		return (NULL);
	for (i = 0; i < x; i++)
	{
	for (n = 0; av[i][n]; n++)
	{
		string[r] = av[i][n];
		r++;
	}
	if (string[r] == '\0')
	{
		string[r++] = '\n';
	}
	}
	return (string);
}
