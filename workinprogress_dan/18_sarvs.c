#include "shell.h"

/**
 * is_chain - this func snoops thru buf and looks for chain delims
 *
 * @info: struct placeholder
 *
 * @buf: chain buf
 *
 * @p: position in buf
 *
 * Return: 1 when we have chain delim or 0 if not
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t y = *p;

	if (buf[y] == '|' && buf[y + 1] == '|')
	{
	buf[y] = 0;
	y++;
	info->cmd_buf_type = CMD_OR;
	}
	else if (buf[y] == '&' && buf[y + 1] == '&')
	{
	buf[y] = 0;
	y++;
	info->cmd_buf_type = CMD_AND;
	}
	else if (buf[y] == ';')
	{
	buf[y] = 0;
	info->cmd_buf_type = CMD_CHAIN;
	}
	else
	return (0);
	*p = y;

	return (1);
}

/**
 * check_chain - should we chain or should we stop?
 *
 * @info: struct placeholder
 *
 * @buf: buf paceholder
 *
 * @p: position in buf
 *
 * @x: start point
 *
 * @len: size of buf
 *
 * Return: retutn nothing
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t x, size_t len)
{
	size_t y = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
	if (info->status)
	{
	buf[x] = 0;
	y = len;
	}
	}

	if (info->cmd_buf_type == CMD_OR)
	{
	if (!info->status)
	{
	buf[x] = 0;
	x = len;
	}
	}

	*p = y;
}

/**
 * replace_alias - this func wil replace an alias
 *
 * @info:struct placeholder
 *
 * Return: 1 if succsessful or otherwise 0
 */

int replace_alias(info_t *info)
{
	int x;
	list_t *node;
	char *p;

	for (x = 0; x < 10; x++)
	{
	node = nodestart(info->alias, info->argv[0], '=');
	if (!node)
	return (0);
	free(info->argv[0]);
	p = _strchr(node->str, '=');
	if (!p)
	return (0);

	p = _strdup(p + 1);
	if (!p)
	return (0);
	info->argv[0] = p;
	}
	return (1);
}

/**

 * @info:  struct placeholder
 *
 * Return: 1 upon successor 0 otherwise
 */

int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
	if (info->argv[x][0] != '$' || !info->argv[x][1])
	continue;

	if (!strcomp(info->argv[x], "$?"))
	{
	replace_string(&(info->argv[x]),
	_strdup(convertnumber(info->status, 10, 0)));
	continue;
	}
	if (!strcomp(info->argv[x], "$$"))
	{
	replace_string(&(info->argv[x]),
	_strdup(convertnumber(getpid(), 10, 0)));
	continue;
	}
	node = nodestart(info->env, &info->argv[x][1], '=');
	if (node)
	{
	replace_string(&(info->argv[x]),
	_strdup(_strchr(node->str, '=') + 1));
	continue;
	}
	replace_string(&info->argv[x], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - this finc wil replace str
 *
 * @old: olde str add
 *
 * @new: new str add
 *
 * Return: 1 if successful or ret 0 if otherwise
 */

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
