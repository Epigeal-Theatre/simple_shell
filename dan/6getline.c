#include "shell.h"
/**
 * input_buf - this func insects our buffer
 *
 * @info: this guy is a struct placeholder
 *
 * @buf: this guy is the buffer address
 *
 * @len: this guy is the length add placeholder
 *
 * Return: bytes read
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t q = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		q = getline(buf, &len_p, stdin);
#else
		q = _getline(info, buf, &len_p);
#endif
		if (q > 0)
		{
			if ((*buf)[q - 1] == '\n')
			{
				(*buf)[q - 1] = '\0'; /* this guy will rm trailing nl */
				q--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = q;
				info->cmd_buf = buf;
			}

		}
	}
	return (q);
}

/**
 * get_input - this function takes up input together
 *
 * @info: struct placeholder
 *
 * Return: number of bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t x, y, len;
	ssize_t q = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	q = input_buf(info, &buf, &len);
	if (q == -1) /* EndOfFile */
		return (-1);
	if (len)

	{
		y = x;
		p = buf + x;

		check_chain(info, buf, &y, x, len);
		while (y < len) /* iterate where there is semicolon or end */
		{
			if (is_chain(info, buf, &y))
				break;
			y++;
		}
		x = y + 1;
		if (x >= len)
		{
			x = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (q);
}


/**
 * read_buf - this func handsles input received in bufer
 *
 * @info: sttruct placeholder
 *
 * @buf: this guy is our buffer
 *
 * @i: this is the size placeholder
 *
 * Return: q
 */

ssize_t read_buf(info_t *info, char *buf, size_t *x)
{
	ssize_t q = 0;

	if (*x)
		return (0);
	q = read(info->readfd, buf, READ_BUF_SIZE);

	if (q >= 0)
		*x = q;
	return (q);
}

/**
 * _getline - this func fetches next line from standard input
 *
 * @info: struct placeholder
 *
 * @ptr: placeholder of addre of ptr to buf
 *
 * @length: size of ptr to buf
 *
 * Return: size sz
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t x, len;
	size_t k;
	ssize_t q = 0, u = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		u = *length;
	if (x == len)
		x = len = 0;

	q = read_buf(info, buf, &len);

	if (q == -1 || (q == 0 && len == 0))
		return (-1);

	c = _strchr(buf + x, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, u, u ? u + k : k + 1);

	if (!new_p)

		return (p ? free(p), -1 : -1);

	if (u)
		_strncat(new_p, buf + x, k - x);
	else
		_strncpy(new_p, buf + x, k - x + 1);

	u += k - x;
	x = k;
	p = new_p;

	if (length)
		*length = u;
	*ptr = p;
	return (u);
}

/**
 * sigintHandler - blocks ctrl-C
 *
 * @sig_num: the signal number
 *
 * Return: void
 */

void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
