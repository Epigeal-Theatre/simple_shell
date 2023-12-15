#include "shell.h"

/**
 * _myenv - this guy tells the curr env
 *
 * @info: Structure carrying args
 *
 * Return: 0
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);

	return (0);

}

/**
 * _getenv - this func finds val of envt var
 *
 * @info: Structure carrying args
 *
 * @name: name
 *
 * Return: val
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);

		if (p && *p)

			return (p);

		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - this func will initialize environment var
 *
 * @info: Structure carrying args
 *
 *  Return:  0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{

		_eputs("Incorrect number of arguements\n");
		return (1);
	}

	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);

}

/**
 * _myunsetenv - this function unsets environment var
 *
 * @info: Structure carrying ars
 *
 *  Return:  0
 */
int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);

}
/**
 * populate_env_list - this func populates ln list
 *
 * @info: Structure carrying args
 *
 * Return:  0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);

	info->env = node;
	return (0);

}
