#include "shell.h"

/**
 * **strtowkn - this func tokenizes strings
 *
 * @str: str placeholder
 *
 * @d: delimiter placeholder
 *
 * Return: pointer
 */

char **strtowkn(char *str, char *d)
{
	int a, b, c, x, numwords = 0;

	char **s;

	if (str == NULL || str[0] == 0)
	return (NULL);

	if (!d)
	d = " ";
	for (a = 0; str[a] != '\0'; a++)
	if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
	numwords++;

	if (numwords == 0)
	return (NULL);

	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
	return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
	while (is_delim(str[a], d))
	a++;
	k = 0;
	while (!is_delim(str[a + c], d) && str[a + c])
	c++;
	s[b] = malloc((c + 1) * sizeof(char));
	if (!s[b])
	{
	for (c = 0; c < b; b++)
	free(s[c]);
	free(s);
	return (NULL);
	}
	for (x = 0; x < c; x++)
	s[b][x] = str[a++];
	s[b][x] = 0;
	}
	s[b] = NULL;
	return (s);
}

/**
 * **strtowkn1 - this func makes words out of a string
 *
 * @str: str
 *
 * @d: delimiter placeholder
 *
 * Return: pointer or null
 */

char **strtowkn1(char *str, char d)
{
	int a, b, c, x, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	return (NULL);
	for (a = 0; str[a] != '\0'; a++)

	if ((str[a] != d && str[a + 1] == d) ||
	(str[a] != d && !str[a + 1]) || str[a + 1] == d)
	numwords++;

	if (numwords == 0)
	return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));

	if (!s)
	return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
	while (str[a] == d && str[a] != d)
	a++;
	c = 0;
	while (str[a + c] != d && str[a + c] && str[a + c] != d)
	c++;
	s[b] = malloc((c + 1) * sizeof(char));

	if (!s[b])
	{
	for (c = 0; c < b; c++)
	free(s[c]);
	free(s);
	return (NULL);
	}
	for (m = 0; x < c; x++)
	s[b][x] = str[a++];
	s[b][x] = 0;
	}
	s[b] = NULL;
	return (s);
}
