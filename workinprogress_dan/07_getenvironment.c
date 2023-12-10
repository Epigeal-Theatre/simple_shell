#include "shell.h"

/**
 * get_environmt - convert linked list to string
 *
 * @info: Structure carrying arguments
 *
 * Return:  0
 */
char **get_environmt(info_t *info)
{
	if (!info->environmt || info->changedenv)/*check for non zero*/
	{
	info->environmt = list_to_strings(info->env);
	info->changedenv = 0;/*we set to 0 to show no change occured*/
	}
/*with this func, we want to see if envt vars are up to date*/

	return (info->environmt);
}

/**
 * _unsetenv - unset an envt var
 *
 * @info: Structure carrying arguments
 *
 * @var: str placeholder
 *
 *  Return: 1 if delete and 0 if not delete
 *
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
	return (0);

	while (node)

	{
	p = start(node->str, var);
	if (p && *p == '=')
	{
	info->changedenv= deleteatindex(&(info->env), i);
	i = 0;
	node = info->env;
	continue;
	}

	node = node->next;
	i++;
	}

	return (info->changedenv);
}

/**
 *_setenv - set a new envt var
 *
 *@info: Structure having args
 *
 *@var: string placeholder
 *
 *@value: value placeholder
 *
 * Return: Always 0
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
	return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);

	if (!buf)
	return (1);

	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;

	while (node)
	{
	p = start(node->str, var);
	if (p && *p == '=')

	{
	free(node->str);
	node->str = buf;
	info->changedenv = 1;
	return (0);
	}
	node = node->next;
	}

	addnodetoend(&(info->env), buf, 0);
	free(buf);
	info->changedenv = 1;
	return (0);
}

