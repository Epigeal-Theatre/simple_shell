#include "shell.h"

/**
 * _strcpy - this func copies str
 *
 * @destination: destination placeholder
 *
 * @source: source placeholder
 *
 * Return: destination ptr
 */

char *_strcpy(char *destination, char *source)
{
	int x = 0;

	if (destination == source || source == 0)
	return (destination);
	while (source[x])
	{
	destination[x] = source[x];
	x++;
	}
	destination[x] = 0;
	return (destination);
}

/**
 * _strdup - this func will makes duplicates of strs
 *
 * @str: string we want to duplicat
 *
 * Return: pointer to new dup str
 */

char *_strdup(const char *str)
{
	int len = 0;
	char *rt;

	if (str == NULL)
	return (NULL);
	while (*str++)
	len++;
	rt = malloc(sizeof(char) * (len + 1));
	if (!rt)
	return (NULL);
	for (len++; len--;)
	ret[len] = *--str;
	return (rt);
}

/**
 *_puts - this func will print strs
 *
 *@str: str we want to print
 *
 * Return: no return value
 */

void _puts(char *str)
{
	int x = 0;

	if (!str)
	return;
	while (str[x] != '\0')

	{
	_putchar(str[x]);
	x++;
	}
}

/**
 * _putchar - this func putchars caharcters to stdout
 *
 * @c: character placeholder
 *
 * Return: 1 upon success and -1 upon error
 */

int _putchar(char c)
{
	static int x;
	static char buf[wbf];


	if (c == BUF_FLUSH || x >= wbf)

	{
	write(1, buf, x);
	x = 0;
	}
	if (c != BUF_FLUSH)
	buf[x++] = c;
	return (1);
}
