#include <stdio.h>

void tortoise(void) __attribute__ ((constructor));

/**
 * tortoise - prints a sentence before the main
 * function is executed
 */
void tortoise(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
