#include "shell.h"

/**
 * myaddnode - this func adds the first node to a list
 *
 * @head: addr pointer to head node
 *
 * @str: str placeholder
 *
 * @num: index placeholder
 *
 * Return: sz
 */

list_t *myaddnode(list_t **head, const char *str, int num)
{
	list_t *nhead;

	if (!head)
	return (NULL);

	nhead = malloc(sizeof(list_t));
	if (!nhead)
	return (NULL);

	setmem((void *)nhead, 0, sizeof(list_t));
	nhead->num = num;
	if (str)
	{
	nhead->str = _strdup(str);

	if (!nhead->str)
	{
	free(nhead);
	return (NULL);
	}

	nhead->next = *head;
	*head = nhead;

	return (nhead);
}

/**
 * addnodetoend - this func adds a node to the end of our list
 *
 * @head: pointer node laceholder
 *
 * @str: placeholder to str
 *
 * @num: placeholder to hist ind
 *
 * Return: sz
 */

list_t *addnodetoend(list_t **head, const char *str, int num)
{
	list_t *nnode, *node;

	if (!head)
	node = *head;
i	nnode = malloc(sizeof(list_t));
	if (!nnode)
	return (NULL);
	setmem((void *)nnode, 0, sizeof(list_t));
	nnode->num = num;
	if (str)
	{
	nnode->str = _strdup(str);
	if (!nnode->str)
	{
	free(nnode);
	return (NULL);
	}
	}
	if (node)
	{
	while (node->next)
	node = node->next;
	node->next = nnode;
	}
	else
	*head = nnode;
	return (nnode);
}


/**
 * printstringlist - this func will print str elements in a list
 *
 * @hd: head placeholder
 *
 * Return: sz x
 */

size_t printstringlist(const list_t *hd)
{
	size_t x = 0;

	while (hd)
	{
	_puts(hd->str ? hd->str : "(nil)");
	_puts("\n");
	hd = hd->next;
	x++;
	}
	return (x);
}

/**
 * deleteatindex - this func deletes the node it is tasked to
 *
 * @head: head placeholder
 *
 * @ind: placeholder for index we want to delete
 *
 * Return: 1 upon success and 0 otherwise
 */

int deleteatindex(list_t **head, unsigned int ind)
{
	list_t *node, *pnode;
	unsigned int x = 0;

	if (!head || !*head)
	return (0);

	if (!ind)
	{
	node = *head;
	*head = (*head)->next;
	free(node->str);
	free(node);
	return (1);
	}
	node = *head;
	while (node)
	{
	if (x == ind)
	{
	pnode->next = node->next;
	free(node->str);
	free(node);
	return (1);
	}
	x++;
	pnode = node;
	node = node->next;
	}
	return (0);
}

/**
 * myfreelist - this func sets all nodes free
 *
 * @hpt: placeholder for head pointer
 *
 * Return: no return value
 */

void myfreelist(list_t **hpt)
{
	list_t *node, *nnode, *head;

	if (!hpt || !*hpt)
	return;
	head = *hpt;
	node = head;
	while (node)
	{
	nnode = node->next;
	free(node->str);
	free(node);
	node = nnode;
	}

	*hpt = NULL;
}
