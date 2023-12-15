#include "shell.h"
/**
 * _strlen - this func will tell the length of our str
 *
 * @s: the string placehoder
 *
 * Return: length
 */
int _strlen(char *s)
{
	int x;

	x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;
	return (x);
}

/**
 * _strcmp - this str compares 2 strings
 *
 * @s1: str 1
 *
 * @s2: s 2
 *
 * Return: (-0) if s1 < s2.(+) s1 > s2 .(0) if s1 == s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);

}


/**
 * starts_with - check whether step starts with journey
 *
 * @journey: str we will search
 *
 * @step: substr we want to fond
 *
 * Return: add of subsequent char of journey or even NULL
 */

char *starts_with(const char *journey, const char *step)
{
	while (*step)
		if (*step++ != *journey++)
			return (NULL);
	return ((char *)journey);
}

/**
 * _strcat - this func concats 2 strings
 *
 * @dest: destination placeholder
 *
 * @src: source placeholder
 *
 * Return: ptr
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;


	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
