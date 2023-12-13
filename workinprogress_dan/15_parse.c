#include "shell.h"

/**
 * dowehavecmd - this func checks if we have an executable cmd
 *
 * @info: struct pllaceholder
 *
 * @path: path
 *
 * Return: 1 if successful and otherwise 0
 */

int dowehavecmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))

	return (0);

	if (st.st_mode & S_IFREG)

	{
	return (1);
	}

	return (0);
}

/**
 * duplicatechars -  this func duplicates characters
 *
 * @pathstr: str path
 *
 * @start: placeholder for starting index
 *
 * @stop: placeholder stopping index
 *
 * Return: ptr to buffer
 */

char *duplicatechars(char *pathstr, int start, int stop)
{
	static char buf[1024];


	int x = 0, y = 0;

	for (y = 0, x = start; x < stop; x++)

	if (pathstr[x] != ':')

	buf[y++] = pathstr[x];

	buf[y] = 0;

	return (buf);
}

/**
 * pathfinder - this func finds path
 *
 * @info: struct placeholder
 *
 * @pathstr: str path laceholder
 *
 * @cmd: cmd
 *
 * Return: full path
 */

char *pathfinder(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, curr_pos = 0;

	char *path;

	if (!pathstr)
	return (NULL);
	if ((stringlength(cmd) > 2) && start(cmd, "./"))
	{
	if (dowehavecmd(info, cmd))
	return (cmd);
	}
	while (1)
	{
	if (!pathstr[x] || pathstr[x] == ':')
	{
	path = duplicatechars(pathstr, curr_pos, x);
	if (!*path)
	strconcat(path, cmd);
	else
	{
	strconcat(path, "/");
	strconcat(path, cmd);
	}
	if (dowehavecmd(info, path))
	return (path);
	if (!pathstr[x])
	break;
	curr_pos = x;
	}
	x++;
	}
	return (NULL);
}
