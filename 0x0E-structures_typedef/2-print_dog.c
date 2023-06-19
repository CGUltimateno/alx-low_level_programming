#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: struct dog to print
 */
void print_dog(struct dog *dog)
{
	if (dog == NULL)
		return;

	if (dog->name == NULL)
		dog->name = "(nil)";
	if (dog->owner == NULL)
		dog->owner = "(nil)";

	printf("Name: %s\nAge: %f\nOwner: %s\n", dog->name, dog->age, dog->owner);
}
