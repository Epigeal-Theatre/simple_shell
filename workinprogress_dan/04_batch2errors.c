#include "shell.h"

/**
 * erratoi - this func converts str to int
 *
 * @s: the str placeholder
 *
 * Return: 0 when no numbers in str and othewrwise -1
 *
 */
int erratoi(char *s)
{
	int x = 0;
	unsigned long int rs = 0;

	if (*s == '+')
	s++;

	for (x = 0;  s[x] != '\0'; x++)
	{
	if (s[x] >= '0' && s[x] <= '9')
	{
	rs *= 10;
	rs += (s[x] - '0');
	if (rs > INT_MAX)
	return (-1);
	}
	else
	return (-1);
	}
	return (rs);
}

/**
 * printerror - this func prints our error msgs
 *
 * @info: struct placeholder
 *
 * @estr: error type placeholder str
 *
 * Return: 0 when no numbers in str otherwise -1
 */

void printerror(info_t *info, char *estr)
{
	_eputs(info->fname);

	_eputs(": ");

	printdecimal(info->line_count, STDERR_FILENO);

	_eputs(": ");

	_eputs(info->argv[0]);

	_eputs(": ");

	_eputs(estr);
}

/**
 * printdecimal - this func pprints  decimal
 *
 * @input: input placeholder
 *
 * @fdec: file descriptor placeholder
 *
 * Return: chars printed
 */

int printdecimal(int input, int fdec)
{
	int (*__putchar)(char) = _putchar;

	int x, ct = 0;

	unsigned int _abs_, crt;

	if (fdec == STDERR_FILENO)
	__putchar = _eputchar;
	if (input < 0)
	{
	_abs_ = -input;
	__putchar('-');
	ct++;
	}

	else
	_abs_ = input;
	crt = _abs_;
	for (x = 1000000000; x > 1; x /= 10)
	{
	if (_abs_ / x)
	{
	__putchar('0' + crt / x);
	ct++;
	}
	crt %= x;
	}

	__putchar('0' + crt);
	ct++;

	return (ct);
}

/**
 * convertnumber - this fun converts numbers
 *
 * @num: no. placeholder
 *
 * @bas: base placeholder
 *
 * @flags: placeholder for arg flags
 *
 * Return: str
 */
char *convertnumber(long int num, int bas, int flags)
{
	static char *array;

	static char buffer[50];

	char sign = 0;

	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
	n = -num;
	sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";

	ptr = &buffer[49];
	*ptr = '\0';

	do	{
	*--ptr = array[n % bas];
	n /= bas;
	} while (n != 0);

	if (sign)
	*--ptr = sign;

	return (ptr);
}

/**
 * commentremover - this func removes comments
 *
 * @buf: str addrress placeholder
 *
 * Return: no value
 */

void commentremover(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
	if (buf[x] == '#' && (!x || buf[x - 1] == ' '))

	{
	buf[x] = '\0';
	break;
	}
}
