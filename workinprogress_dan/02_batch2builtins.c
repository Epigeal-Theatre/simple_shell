#include "shell.h"

/**
 * myhist - this func will display history list
 *
 * @info: structure carrying args
 *
 *  Return: 0
 */

int myhist(info_t *info)
{
	print_list(info->hist);
	return (0);
}

/**
 * unsetalias - this func will set alias to st
 *
 * @info: struct placeholder
 *
 * @str: alias str
 *
 * Return: 0 upon success and otherwise 1
 */

int unsetalias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
	return (1);
	c = *p;
	*p = 0;

	rt = deleteatindex(&(info->alias),
	getindex(info->alias, nodestart(info->alias, str, -1)));
	*p = c;
	return (rt);
}

/**
 * setalias - this func will set an alias to str
 *
 * @info: struct placeholder
 *
 * @str: alias str
 *
 * Return: 0 upon success and otherwise  1
 */

int setalias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');

	if (!p)
	return (1);

	if (!*++p)

	return (unsetalias(info, str));

	unsetalias(info, str);

	return (addnodetoend(&(info->alias), str, 0) == NULL);
}

/**
 * printmyalias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */

int printmyalias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
	p = _strchr(node->str, '=');
	for (a = node->str; a <= p; a++)
	_putchar(*a);
	_putchar('\'');
	_puts(p + 1);
	_puts("'\n");
	return (0);
	}
	return (1);
}

/**
 * alias - this func is our version of the alias
 *
 * @info: Structure carrying args
 *
 *  Return: 0
 */

int alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)

	{
	node = info->alias;
	while (node)
	{
	printmyalias(node);
	node = node->next;
	}

	return (0);

	}
	for (i = 1; info->argv[i]; i++)
	{
	p = _strchr(info->argv[i], '=');
	if (p)
	setalias(info, info->argv[i]);
	else
	printmyalias(nodestart(info->alias, info->argv[i], '='));
	}

	return (0);
}

