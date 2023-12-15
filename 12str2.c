#include "shell.h"

/**
 * _strcpy - this func copies str
 *
 * @dest: destination placeholder
 *
 * @src: source placeholder
 *
 * Return: destination ptr
 */

char *_strcpy(char *dest, char *src)
{
	int x;

	x = 0;

	if (dest == src || src == 0)
		return (dest);

	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
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
	int length = 0;

	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;

	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);

	for (length++; length--;)
		ret[length] = *--str;
	return (ret);

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
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}

	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);

}
