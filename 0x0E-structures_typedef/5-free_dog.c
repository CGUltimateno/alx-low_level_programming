#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory allocated for a struct dog
 * @d: struct dog to free
 */
void free_dog(dog_t *dog)
{
	if (dog)
	{
		free(dog->name);
		free(dog->owner);
		free(dog);
	}
}
