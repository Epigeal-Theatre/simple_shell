#include "shell.h"


/**
*_memset - this func will perform memset
*
*@s: pointer to memory
*
*@b: bytes to fill
*
*@n: number of bytes
*
*Return: sz
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}

/**
 * ffree - this func will freee strings
 *
 * @pp: placeholder for str
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)

		return;
	while (*pp)
		free(*pp++);
	free(a);

}
/**
 * _realloc - this func is used to realloc
 *
 * @ptr: previous malloc pointer
 *
 * @old_size: old size block
 *
 * @new_size: new size block
 *
 * Return: pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));

	if (!new_size)
		return (free(ptr), NULL);

	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);


	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);

	return (p);
}
