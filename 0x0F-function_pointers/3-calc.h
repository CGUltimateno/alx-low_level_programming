#ifndef CALC_H
#define CALC_H
/**
 * struct lol - A struct lol.
 * @lol: The operator.
 * @f: The associated function.
 */
typedef struct lol
{
	char *lol;
	int (*f)(int a, int b);
} lol_t;

int lol_add(int a, int b);
int lol_sub(int a, int b);
int lol_mul(int a, int b);
int lol_div(int a, int b);
int lol_mod(int a, int b);
int (*get_lol_func(char *s))(int, int);

#endif
