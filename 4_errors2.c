#include "shell.h"
/**
 * _erratoi - this func converts str to int
 *
 * @s: the str placeholder
 *
 * Return: 0 when no numbers in str and othewrwise -1
 *
 */
int _erratoi(char *s)
{
	int x = 0;
	unsigned long int myrst = 0;

	if (*s == '+')
		s++;
	for (x = 0;  s[x] != '\0'; x++)
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			myrst *= 10;
			myrst += (s[x] - '0');
			if (myrst > INT_MAX)
				return (-1);
		}

		else
			return (-1);
	}
	return (myrst);

}



/**
 * print_error - this func prints our error msgs
 *
 * @info: struct placeholder
 *
 * @estr: error type placeholder str
 *
 * Return: 0 when no numbers in str otherwise -1
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - this func pprints  decimal
 *
 * @input: input placeholder
 *
 * @xfd: file descriptor placeholder
 *
 * Return: chars printed
 */

int print_d(int input, int xfd)
{
	int (*__putchar)(char) = _putchar;

	int x, ct = 0;/*ct is our count while curr is current*/
	unsigned int _abs_, curr;

	if (xfd == STDERR_FILENO)
		__putchar = _eputchar;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		ct++;
	}

	else
		_abs_ = input;
	curr = _abs_;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (_abs_ / x)
		{
			__putchar('0' + curr / x);
			ct++;
		}
		curr %= x;
	}
	__putchar('0' + curr);
	ct++;

	return (ct);
}

/**
 * convert_number - this fun converts numbers
 *
 * @num: no. placeholder
 *
 * @base: base placeholder
 *
 * @flags: placeholder for arg flags
 *
 * Return: str
 */

char *convert_number(long int num, int base, int flags)
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
		*--ptr = array[n % base];
		n /= base;

	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}
/**
 * remove_comments - this func removes comments
 *
 * @buf: str addrress placeholder
 *
 * Return: no value
 */

void remove_comments(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
		if (buf[x] == '#' && (!x || buf[x - 1] == ' '))
		{
			buf[x] = '\0';
			break;
		}

}
