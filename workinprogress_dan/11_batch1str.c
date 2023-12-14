#include "shell.h"

/**
 * stringlength - this func will tell the length of our str
 *
 * @sz: the string placehoder
 *
 * Return: length
 */
int stringlength(char *sz)
{
	int x = 0;

	if (!sz)
	return (0);

	while (*sz++)
	x++;

	return (x);
}

/**
 * strcomp - this str compares 2 strings
 *
 * @str1: str 1
 *
 * @str2: str 2
 *
 * Return: (-0) if s1 < s2.(+) s1 > s2 .(0) if s1 == s2
 */
int strcomp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
	if (*str1 != *str2)
	return (*str1 - *str2);
	str1++;
	str2++;
	}
	if (*str1 == *str2)
	return (0);
	else
	return (*str1 < *str2 ? -1 : 1);

}

/**
 * start - check whether step starts with journey
 *
 * @journey: str we will search
 *
 * @step: substr we want to fond
 *
 * Return: add of subsequent char of journey or even NULL
 */
char *start(const char *journey, const char *step)
{
	while (*step)
	if (*step++ != *journey++)
	return (NULL);
	return ((char *)journey);
}

/**
 * strconcat - this func concats 2 strings
 *
 * @destination: destination placeholder
 *
 * @source: source placeholder
 *
 * Return: ptr
 */
char *strconcat(char *destination, char *source)
{
	char *rt = destination;

	while (*destination)
	destination++;
	while (*source)
	*destination++ = *source++;
	*destination = *source;
	return (rt);
}
