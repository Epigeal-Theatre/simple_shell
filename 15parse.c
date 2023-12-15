#include "shell.h"


/**
 * is_cmd - this func checks if we have an executable cmd
 *
 * @info: struct pllaceholder
 *
 * @path: path
 *
 * Return: 1 if successful and otherwise 0
 */
int is_cmd(info_t *info, char *path)
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
 * dup_chars -  this func duplicates characters
 *
 * @pathstr: str path
 *
 * @start: placeholder for starting index
 *
 * @stop: placeholder stopping index
 *
 * Return: ptr to buffer
 */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int x = 0;
	int l = 0;

	for (l = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buf[l++] = pathstr[x];

	buf[l] = 0;

	return (buf);
}
/**
 * find_path - this func finds path
 *
 * @info: struct placeholder
 *
 * @pathstr: str path laceholder
 *
 * @cmd: cmd
 *
 * Return: full path
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, currpost = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}

	while (1)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			path = dup_chars(pathstr, currpost, x);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}

			if (is_cmd(info, path))
				return (path);
			if (!pathstr[x])
				break;

			currpost = x;
		}
		x++;
	}
	return (NULL);
}
