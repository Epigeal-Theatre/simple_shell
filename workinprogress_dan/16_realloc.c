#include "shell.h"

/**
*setmem - this func will perform memset
*
*@sz: pointer to memory
*
*@by: bytes to fill
*
*@n: number of bytes
*
*Return: sz
*/
char *setmem(char *sz, char by, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)

	s[x] = by;

	return (sz);
}

/**
 * ffree - this func will freee strings
 *
 * @dp: placeholder for str
 */

void ffree(char **dp)
{
	char **x = dp;

	if (!dp)
	return;

	while (*dp)
	free(*dp++);

	free(x);
}

/**
 * _realloc - this func is used to realloc
 *
 * @ptr: previous malloc pointer
 *
 * @os: old size block
 *
 * @ns: new size block
 *
 * Return: pointer
 */

void *_realloc(void *ptr, unsigned int os, unsigned int ns)
{
	char *p;

	if (!ptr)
	return (malloc(ns));
	if (!ns)
	
	return (free(ptr), NULL);

	if (ns == os)
	return (ptr);

	p = malloc(ns);
	if (!p)
	return (NULL);

	os = os < ns ? os : ns;
	while (os--)
	
	p[os] = ((char *)ptr)[os];
	free(ptr);

	return (p);
}
