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
	int x;

	x = 0;

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

	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}

	if (c != BUF_FLUSH)
		buf[x++] = c;

	return (1);
}
/**
 * _putfd - this func writes a character to file descriptor
 *
 * @c: character placeholder
 *
 * @xfd: file descriptor placeholder
 *
 * Return: 1 upon success and otherwise -1.
 */

int _putfd(char c, int xfd)
{
	static int x;

	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)

	{
		write(xfd, buf, x);
		x = 0;
	}

	if (c != BUF_FLUSH)
		buf[x++] = c;

	return (1);

}
/**
 *_putsfd - this function prints input strs
 *
 * @str: str placeholder
 *
 * @xfd: the filedescriptor placeholder
 *
 * Return: chars
 */

int _putsfd(char *str, int xfd)
{
	int x;

	x = 0;

	if (!str)
		return (0);

	while (*str)
	{
		x += _putfd(*str++, xfd);
	}
	return (x);

}

