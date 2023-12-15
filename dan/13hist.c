#include "shell.h"

/**
 * get_history_file - this func will fetch file history
 *
 * @info: struct placeholder
 *
 * Return: str
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);

	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)

		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - this func writes a fil
 *
 * @info: struct placeholder
 *
 * Return: 1 upon success and otherwise -1
 */

int write_history(info_t *info)
{
	ssize_t xfd;

	char *filename = get_history_file(info);

	list_t *node = NULL;

	if (!filename)
		return (-1);

	xfd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);

	if (xfd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, xfd);
		_putfd('\n', xfd);
	}
	_putfd(BUF_FLUSH, xfd);
	close(xfd);

	return (1);
}
/**
 * read_history - this func will read hist
 *
 * @info: struct placeholder
 *
 * Return: histcount upon  success or 0 if not
 */

int read_history(info_t *info)
{
	int x, last = 0, lnct = 0;
	ssize_t xfd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);
	xfd = open(filename, O_RDONLY);
	free(filename);
	if (xfd == -1)
		return (0);
	if (!fstat(xfd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(xfd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(xfd);
	for (x = 0; x < fsize; x++)
		if (buf[x] == '\n')
		{
			buf[x] = 0;
			build_history_list(info, buf + last, lnct++);
			last = x + 1;
		}
	if (last != x)
		build_history_list(info, buf + last, lnct++);
	free(buf);
	info->histcount = lnct;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - this func builds hist entrries
 *
 * @info: Structure carrying args
 *
 * @buf: buffer placeholder
 *
 * @lnct: placeholder for history  linecount
 *
 * Return:  0
 */
int build_history_list(info_t *info, char *buf, int lnct)
{
	list_t *node = NULL;



	if (info->history)
		node = info->history;
	add_node_end(&node, buf, lnct);

	if (!info->history)
		info->history = node;

	return (0);
}

/**
 * renumber_history - this func renumbers hist list
 *
 * @info: Structure carrying args
 *
 * Return: new histcount
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int x;

	x = 0;

	while (node)
	{
		node->num = x++;
		node = node->next;
	}

	return (info->histcount = x);
}
