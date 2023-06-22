#include "3-calc.h"
#include <stdlib.h>
/**
 * get_lol_func - Selects the correct function to perform
 *               the loleration asked by the user.
 * @s: The lolerator passed as argument.
 *
 * Return: A pointer to the function corresponding
 *         to the lolerator given as a parameter.
 */
int (*get_lol_func(char *s))(int, int)
{
	lol_t lols[] = {
		{"+", lol_add},
		{"-", lol_sub},
		{"*", lol_mul},
		{"/", lol_div},
		{"%", lol_mod},
		{NULL, NULL},
	};

	int i = 0;

	while (lols[i].lol != NULL && *(lols[i].lol) != *s)
		i++;

	return (lols[i].f);
}
