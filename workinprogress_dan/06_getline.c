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
	ssize_t btrd = 0;

	size_t len_p = 0;

	if (!*len)
/* this condition checks if our buffer length is empty 0 */
	{
/*if our buffer is actuall empty, we set it to NULL and free it*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
/*now we utilize getline to to know nytes read*/
#if USE_GETLINE
		btrd = getline(buf, &len_p, stdin);
#else
		btrd = _getline(info, buf, &len_p);
#endif

/*this next condition checks if any bytes were actually read*/
	if (btrd > 0)
	{
	if ((*buf)[btrd - 1] == '\n')
	{
	/*we have bytes in buffer.now we need to rm T new ln*/
	(*buf)[btrd - 1] = '\0';
	btrd--;
	}
	info->linecount_flag = 1;
	remove_comments(*buf);
	build_history_list(info, *buf, info->histcount++);
	if (_strchr(*buf, ';'))
	/*now we check for presence of ; semicolon implying a cmd chain*/
	{
	*len = btrd;
	info->cmd_buf = buf;
	}
	}
	}
	/*return the number of bytes we read, btrd*/
	return (btrd);
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
	static size_t xi, xj, len;
/*we need static variabls because we want values to persiste between func calls*/
/*xi and xj store the length of the buffer*/
	ssize_t btrd = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);/*we need to call buf flush func to clear buffer*/
	btrd = input_buf(info, &buf, &len);/*call the func that reads buffer content*/
	if (btrd == -1) /* inspect bef content to the EOF */
	return (-1);

	if (len)/*we want check if for a fact there is content in buffer*/
	{
	xj = xi; /*we need to initialize our iterators*/
	p = buf + xi; /*we need to prep our pointer to store content*/

	check_chain(info, buf, &xj, xi, len);
	while (xj < len) /* now we need to snoop through till we find ;delim */
	{
	if (is_chain(info, buf, &xj))
	break;
	xj++;
	}

	xi = xj + 1;
	if (xi >= len)
	{
	xi = len = 0;
	info->cmd_buf_type = CMD_NORM;
	}

	*buf_p = p;
	return (_strlen(p));
	}

	*buf_p = buf;/*we snoop through repeatedly while resetting buffer post*/
	return (btrd); /* we finally return bytes read or lengt from _getline() */
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
 * Return: btrd
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t btrd = 0;

	if (*i)/*this condition checksif pointer position is non zero*/
	return (0);/*we return zero to mean we actually have stuff in buffer*/

	btrd = read(info->readfd, buf, READ_BUF_SIZE);/*we call read func*/

	if (btrd >= 0)/*we read bufer conent and update position repeatedly*/
	*i = btrd;

	return (btrd);/*we return what we read*/
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
	static size_t xi, len;
	size_t k;
	ssize_t btrd = 0, sz = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;/*we snoop into *ptr for text and store it in sz*/
	if (p && length)
	sz = *length;

	if (i == len)/*after reading a line, we start again*/
	i = len = 0;

	btrd = read_buf(info, buf, &len);
	/*we call the read func to check if read well*/
	if (btrd == -1 || (btrd == 0 && len == 0))
	/*if there are errors, we stop and report*/
	return (-1);

	c = _strchr(buf + i, '\n');/*we look at the end of line we read*/
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, sz, sz ? sz + k : k + 1);/*we reallocate space for new line*/

	if (!new_p) /*if there are issues, malloc fails*/
	else
	_strncpy(new_p, buf + i, k - i + 1);
/*if there were no issues, we add new text to old text.*/
	sz += k - i;
	i = k;
	p = new_p;
/*now we account for what has been put together and update counters*/
	if (length)

	*length = sz;
	*ptr = p;
/*we use counters to update new size to length of buffer*/
	return (sz);/*we return size*/
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	/*above guy prints new line character*/
	_puts("$ ");
	/*above guy prints dollar sign, indicating readiness to take promps*/
	_putchar(BUF_FLUSH);
	/*above guys flushes the bufer*/
}

