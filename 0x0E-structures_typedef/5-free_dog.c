#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory allocated for a struct dog
 * @d: struct dog to free
 */
void free_dog(dog_t *x)
{
	if (x)
	{
		free(x->name);
		free(x->owner);
		free(x);
	}
}
