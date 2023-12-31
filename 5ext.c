#include "shell.h"
/**
 **_strncpy - this func will cpy strings
 *
 *@dest: destination placeholder
 *
 *@src: source placeholder
 *
 *@n: chars to copy
 *
 *Return: concatenated str
 */
char *_strncpy(char *dest, char *src, int n)
{
	int x, y;

	char *s = dest;

	x = 0;

	while (src[x] != '\0' && x < n - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < n)
	{
		y = x;
		while (y < n)
		{
			dest[y] = '\0';
			y++;
		}
	}

	return (s);
}

/**
 **_strncat -  tis fun concats 2 strs
 *@dest: str 1
 *@src: str 2
 *@n: max bytes
 *Return: str
 */

char *_strncat(char *dest, char *src, int n)
{
	int x, y;
	char *s = dest;

	x = 0;

	y = 0;

	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0' && y < n)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	if (y < n)
		dest[x] = '\0';
	return (s);
}


/**
 **_strchr - this func identifies chars in srt
 *@s: str placeholder
 *@c: the character to look for
 *Return: return:
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);

	} while (*s++ != '\0');


	return (NULL);
}
