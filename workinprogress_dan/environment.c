#include "shell.h"

/**
 * envt - this guy tells the curr env
 *
 * @info: Structure carrying args
 *
 * Return: 0
 */

int envt(info_t *info)
{
	printstringlist(info->env);
	return (0);
}

/**
 * getenvt - this func finds val of envt var
 *
 * @info: Structure carrying args
 *
 * @name: name
 *
 * Return: val
 */
char *getenvt(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)

	{
	p = start(node->str, name);

	if (p && *p)

	return (p);
	node = node->next;
	}

	return (NULL);
}

/**
 * setenvironment - this func will initialize environment var
 *
 * @info: Structure carrying args
 *
 *  Return:  0
 */

int setenvironment(info_t *info)
{
	if (info->argc != 3)
	{
	_eputs("Number of arguments you entered is Incorrect\n");
	return (1);
	}

	if (_setenv(info, info->argv[1], info->argv[2]))
	return (0);
	return (1);
}

/**
 * unsetenvironment - this function unsets environment var
 *
 * @info: Structure carrying ars
 *
 *  Return:  0
 */

int unsetenvironment(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
	_eputs("we need more arguments than that.\n");
	return (1);

	}
	for (i = 1; i <= info->argc; i++)
	_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populatemylist - this func populates ln list
 *
 * @info: Structure carrying args
 *
 * Return:  0
 */
int populatemylist(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environment[i]; i++)
	addnodetoend(&node, environment[i], 0);
	info->env = node;
	return (0);
}
