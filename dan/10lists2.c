#include "shell.h"

/**
 * list_len - this func worries about the length of lst
 *
 * @h: pointer ho head
 *
 * Return: sz
 */
size_t list_len(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		h = h->next;
		x++;
	}
	return (x);
}
/**
 * list_to_strings - this func makes an array of str
 *
 * @head: placeholder for head pointer
 *
 * Return: string
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t x = list_len(head), y;
	char **strs;
	char *str;

	if (!head || !x)
		return (NULL);
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
		return (NULL);

	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);

		if (!str)
		{
			for (y = 0; y < x; y++)
				free(strs[y]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[x] = str;
	}
	strs[x] = NULL;
	return (strs);
}


/**
 * print_list -this func prins the elements of list
 *
 * @h: placeholder for ptr to head node
 *
 * Return: size x
 */

size_t print_list(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		x++;
	}
	return (x);
}


/**
 * node_starts_with - this func fetches nodes that begin in prefixes
 *
 * @node: placeholder for ptr
 *
 * @prefix: placeholder for str
 *
 * @c: placeholder for subsequent char
 *
 * Return: return
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);

		if (p && ((c == -1) || (*p == c)))
			return (node);

		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - this func helps fetch the indices of nodes
 *
 * @head: placeholder for head node
 *
 * @node: placeholder for ptr to node
 *
 * Return: index
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}
