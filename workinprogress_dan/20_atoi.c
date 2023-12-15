#include "shell.h"

/**
 * interactive - confirms interactive mode for our shell
 *
 * @info: struct placeholder
 *
 * Return: 1 on interactive and 0 if not
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - scans for delimiters
 *
 * @c: placeholder for char under examination
 *
 * @delimiter: this is the delimiter
 *
 * Return: 1 for trueand  0 on false case
 */

int is_delim(char c, char *delimiter)
{
	while (*delimiter)

		if (*delimiter++ == c)
			return (1);

	return (0);
}

/**
 *_isalpha - scans if character is alphabetic or not
 *
 *@c: character we are checking
 *
 *Return: 1 should c bealpha and 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

		return (1);
	else
		return (0);
}
/**
 *_atoi - this func converts str to int
 *
 *@s: the str we want to convert
 *
 *Return: 0
 */

int _atoi(char *s)
{
	int x, sign = 1, flag = 0, out;
	unsigned int rs = 0;

	for (x = 0;  s[x] != '\0' && flag != 2; x++)
	{
		if (s[x] == '-')
			sign *= -1;


		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			rs *= 10;
			rs += (s[x] - '0');
		}

		else if (flag == 1)
			flag = 2;
	}


	if (sign == -1)
		out = -rs;
	else
		out = rs;

	return (out);
}
