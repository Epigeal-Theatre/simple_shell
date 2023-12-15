#include "shell.h"

/**
 * interactive - will return 1 when shell is interactive and 0 if != true
 *
 * @info: struct placeholder
 *
 * Return: 1 if interactive mode, 0 if not interactive mode
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - this func checks if char is delimiter
 *
 * @c: placeholder for char to check
 *
 * @delim: placeholder for delimiter to str
 *
 * Return:  will 1 if true and 0 if false
 */

int is_delim(char c, char *delim)
{
	while (*delim)

		if (*delim++ == c)
			return (1);
	return (0);

}

/**
 *_isalpha - this func scans for alphabetic characters
 *
 *@c: c placeholder
 *
 *Return: 1 when c is alphabetic and 0 if not
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);

	else

		return (0);


}

/**
 *_atoi - this func will convert str to int
 *
 *@s: str placeholder
 *
 *Return: 0 if we have no no's in str
 */

int _atoi(char *s)
{
	int x, sign = 1, flag = 0, outp;

	unsigned int myrst = 0;

	for (x = 0;  s[x] != '\0' && flag != 2; x++)
	{
		if (s[x] == '-')
			sign *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			myrst *= 10;
			myrst += (s[x] - '0');
		}

		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		outp = -myrst;
	else
		outp = myrst;

	return (outp);
}
