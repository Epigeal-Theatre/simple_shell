#include "shell.h"

/**
 * infoclear -this func is used to clear
 *
 * @info: struct placeholder
 */

void infoclear(info_t *info)
{
	info->arg = NULL;

	info->argv = NULL;

	info->path = NULL;

	info->argc = 0;
}

/**
 * infoset - this func is used to set
 *
 * @info: struct placeholder
 *
 * @av: arg placeholder
 */

void infoset(info_t *info, char **av)
{
	int x = 0;

	info->fn = av[0];
	if (info->arg)
	{
	info->argv = strtowkn(info->arg, " \t");
	if (!info->argv)
	{

	info->argv = malloc(sizeof(char *) * 2);

	if (info->argv)
	{
	info->argv[0] = _strdup(info->arg);
	info->argv[1] = NULL;
	}
	}
	for (x = 0; info->argv && info->argv[x]; x++)
	;
	info->argc = x;
	replace_alias(info);
	replace_vars(info);
	}
}

/**
 * infofree - this func will free
 *
 * @info: struct placeholder
 *
 * @all: placeholder
 */

void infofree(info_t *info, int all)
{
	ffree(info->argv);

	info->argv = NULL;

	info->path = NULL;
	if (all)

	{
	if (!info->cmd_buf)
	free(info->arg);

	if (info->env)
	myfreelist(&(info->env));

	if (info->hist)
	myfreelist(&(info->hist));

	if (info->alias)
	myfreelist(&(info->alias));

	ffree(info->environmt);

	info->environmt = NULL;
	bfree((void **)info->cmd_buf);

	if (info->readfd > 2)
	close(info->readfd);
	_putchar(BUF_FLUSH);
	}
}

