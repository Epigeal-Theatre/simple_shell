#include "shell.h"

/**
 * tokenarray -	tokenizes a string into an array of arguments.
 * @str:	string to tokenize.
 * Return:	pointer to argument array.
 */
char **tokenarray(char *str)
{
	int i = 0;
	char **arg = NULL;
	char *token = NULL;
	char delim[] = " ";

	token = strtok(str, delim);
	if (_strcmp(token, "exit") == 0)
		successandfree(str, NULL);

	arg = malloc(sizeof(char *) * (ARG_LIMIT + 1));
	if (arg == NULL)
		errorandfree(str, NULL);

	arg[0] = malloc(strlen(token) + 1);
	if (arg[0] == NULL)
		errorandfree(str, NULL);
	_strncpy(arg[0], token, (strlen(token) + 1));

	for (i = 1; token != NULL && i < ARG_LIMIT; i++)
	{
		token = strtok(NULL, delim);

		if (token)
		{
			arg[i] = malloc(strlen(token) + 1);
			if (arg[i] == NULL)
				errorandfree(str, arg);

			_strncpy(arg[i], token, (strlen(token) + 1));
		}
	}
	arg[i] = NULL;
	return (arg);
}

/**
 * errorandfree -	prints error message and frees 2 buffers.
 * @buf1:	first buffer.
 * @buf2:	second buffer(can be NULL).
 * return:	nothing.
 */
void errorandfree(char *buf1, char **buf2)
{
	int i;

	perror("Error: ");
	fflush(stdin);
	if (buf1)
		free(buf1);
	if (buf2)
	{
		for (i = 0; buf2[i]; i++)
			free(buf2[i]);
		free(buf2);
	}

	exit(EXIT_FAILURE);
}

/**
 * successandfree -	frees 2 buffers and exits.
 * @buf1:	first buffer.
 * @buf2:	second buffer(can be NULL).
 * return:	nothing.
 */
void successandfree(char *buf1, char **buf2)
{
	int i;

	fflush(stdin);
	if (buf1)
		free(buf1);
	if (buf2)
	{
		for (i = 0; buf2[i]; i++)
			free(buf2[i]);
		free(buf2);
	}
	exit(EXIT_SUCCESS);
}
