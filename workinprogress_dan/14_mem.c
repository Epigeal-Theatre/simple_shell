#include "shell.h"

/**
 * bfree - this function frees pointers
 *
 * @ptr: ptr placeholder
 *
 * Return: 1 upon freeing and  otherwise 0
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)

	{
	free(*ptr);
	*ptr = NULL;

	return (1);
	}

	return (0);
}
