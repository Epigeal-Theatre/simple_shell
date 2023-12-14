#include "shell.h"

/**
 * fetchfilehist - this func will fetch file history
 *
 * @info: struct placeholder
 *
 * Return: str
 */

char *fetchfilehist(info_t *info)
{
	char *buf, *dir;

	dir = getenvt(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (stringlength(dir) + stringlength(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	strconcat(buf, "/");
	strconcat(buf, HIST_FILE);
	return (buf);
}
/**
 * writehist - this func writes a fil
 *
 * @info: struct placeholder
 *
 * Return: 1 upon success and otherwise -1
 */
int writehist(info_t *info)
{
	ssize_t fdec;
	char *fn = fetchfilehist(info);

	list_t *node = NULL;

	if (!fn)
	return (-1);

	fdec = open(fn, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fn);
	if (fdec == -1)
	return (-1);

	for (node = info->hist; node; node = node->next)
	{
		_putsfdec(node->str, fdec);
		_putfdec('\n', fdec);
	}
	_putfdec(BUF_FLUSH, fdec);
	close(fdec);
	return (1);
}

/**
 * readhist - this func will read hist
 *
 * @info: struct placeholder
 *
 * Return: histcount upon  success or 0 if not
 */
int readhist(info_t *info)
{
	int x, last = 0, lnct = 0;
	ssize_t fdec, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *fn = fetchfilehist(info);

	if (!fn)
	return (0);
	fdec = open(fn, O_RDONLY);
	free(fn);
	if (fdec == -1)
	return (0);
	if (!fstat(fdec, &st))
	fsize = st.st_size;
	if (fsize < 2)
	return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
	return (0);
	rdlen = read(fdec, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
	return (free(buf), 0);
	close(fdec);
	for (x = 0; x < fsize; x++)
	if (buf[x] == '\n')
	{
	buf[x] = 0;
	histbuilder(info, buf + last, lnct++);
	last = x + 1;
	}
	if (last != x)
	histbuilder(info, buf + last, lnct++);
	free(buf);
	info->histcount = lnct;
	while (info->histcount-- >= HIST_MAX)
	deleteatindex(&(info->hist), 0);
	renumberhist(info);
	return (info->histcount);
}

/**
 * histbuilder - this func builds hist entrries
 *
 * @info: Structure carrying args
 *
 * @buf: buffer placeholder
 *
 * @lnct: placeholder for history  linecount
 *
 * Return:  0
 */

int histbuilder(info_t *info, char *buf, int lnct)
{
	list_t *node = NULL;

	if (info->hist)
	node = info->hist;
	addnodetoend(&node, buf, lnct);
	if (!info->hist)
	info->hist = node;
	return (0);
}

/**
 * renumberhist - this func renumbers hist list
 *
 * @info: Structure carrying args
 *
 * Return: new histcount
 */
int renumberhist(info_t *info)
{
	list_t *node = info->hist;
	int x = 0;

	while (node)
	{
	node->num = x++;
	node = node->next;
	}

	return (info->histcount = x);
}
