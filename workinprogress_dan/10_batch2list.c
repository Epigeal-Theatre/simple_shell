#include "shell.h"

/**
 * lengthoflist - this func worries about the length of lst
 *
 * @hp: pointer ho head
 *
 * Return: sz
 */
size_t lengthoflist(const list_t *hp)
{
	size_t x = 0;

	while (hp)

	{
	hp = hp->next;
	x++;
	}

	return (x);
}

/**
 * list2string - this func makes an array of str
 *
 * @head: placeholder for head pointer
 *
 * Return: string
 */

char **list2string(list_t *head)
{
	list_t *node = head;
	size_t x = lengthoflist(head), y;
	char **strs;
	char *str;

	if (!head || !x)
	return (NULL);
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
	return (NULL);
	for (x = 0; node; node = node->next, x++)
	{
	str = malloc(stringlength(node->str) + 1);
	if (!str)
	{
	for (y = 0; y < x; y++)
	free(strs[y]);
	free(strs);
	return (NULL);

	}
	strs[x] = NULL;
	return (strs);
}


/**
 * printlist -this func prins the elements of list
 *
 * @hd: placeholder for ptr to head node
 *
 * Return: size x
 */

size_t printlist(const list_t *hd)
{
	size_t x = 0;

	while (hd)
	{
	_puts(convertnumber(hd->num, 10, 0));
	_putchar(':');
	_putchar(' ');
	_puts(h->str ? h->str : "(nil)");
	_puts("\n");
	hd = hd->next;
	x++;
	}
	return (x);
}

/**
 * nodestart - this func fetches nodes that begin in prefixes
 *
 * @node: placeholder for ptr
 *
 * @prefix: placeholder for str
 *
 * @c: placeholder for subsequent char
 *
 * Return: return
 */
list_t *nodestart(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{

	p = start(node->str, prefix);

	if (p && ((c == -1) || (*p == c)))
	return (node);

	node = node->next;
	}
	return (NULL);
}

/**
 * getindex - this func helps fetch the indices of nodes
 *
 * @hd: placeholder for head node
 *
 * @node: placeholder for ptr to node
 *
 * Return: index
 */

ssize_t getindex(list_t *hd, list_t *node)
{
	size_t x = 0;

	while (hd)
	{
	if (hd == node)
	return (x);

	hd = hd->next;
	x++;
	}

	return (-1);
}
