#include "shell.h"

/**
 *_eputs - this function prints input str
 *
 * @str: this is the string we want to print
 *
 * Return: no return value
 */
void _eputs(char *str)
{
	int x = 0;

	if (!str)
	return;

	while (str[x] != '\0')

	{
	_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - this function prints character to standard error
 *
 * @c: character placeholder
 *
 * Return: 1 upon success and -1 otherwise
 */

int _eputchar(char c)
{
	static int x;
	static char buf[wbf];

	if (c == BUF_FLUSH || x >= wbf)
	{
	write(2, buf, x);
	x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 * _putfdec - this func writes a character to file descriptor
 *
 * @c: character placeholder
 *
 * @fdec: file descriptor placeholder
 *
 * Return: 1 upon success and otherwise -1.
 */

int _putfdec(char c, int fdec)
{
	static int x;
	static char buf[wbf];

	if (c == BUF_FLUSH || x >= wbf)

	{
	write(fdec, buf, x);
	x = 0;

	}
	if (c != BUF_FLUSH)
	buf[x++] = c;

	return (1);
}

/**
 *_putsfdec - this function prints input strs
 *
 * @str: str placeholder
 *
 * @fdec: the filedescriptor placeholder
 *
 * Return: chars
 */

int _putsfdec(char *str, int fdec)
{
	int x = 0;

	if (!str)
	return (0);

	while (*str)

	{
	x += _putfdec(*str++, fdec);
	}

	return (x);
}
