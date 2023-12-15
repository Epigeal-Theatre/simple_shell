#include "shell.h"
/**
 * **strtow - this func tokenizes strings
 *
 * @str: str placeholder
 *
 * @d: delimiter placeholder
 *
 * Return: pointer
 */

char **strtow(char *str, char *d)
{
	int x, y, l, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);

	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (is_delim(str[x], d))
			x++;
		l = 0;
		while (!is_delim(str[x + l], d) && str[x + l])
			l++;
		s[y] = malloc((l + 1) * sizeof(char));
		if (!s[y])
		{
			for (l = 0; l < y; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}

		for (m = 0; m < l; m++)
			s[y][m] = str[x++];
		s[y][m] = 0;
	}
	s[y] = NULL;

	return (s);
}

/**
 * **strtow2 - this func makes words out of a string
 *
 * @str: str
 *
 * @d: delimiter placeholder
 *
 * Return: pointer or null
 */

char **strtow2(char *str, char d)
{
	int x, y, l, m, numwords = 0;

	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		l = 0;
		while (str[x + l] != d && str[x + l] && str[x + l] != d)
			l++;
		s[y] = malloc((l + 1) * sizeof(char));
		if (!s[y])
		{
			for (l = 0; l < y; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < l; m++)
			s[y][m] = str[x++];
		s[y][m] = 0;
	}
	s[y] = NULL;
	return (s);
}
