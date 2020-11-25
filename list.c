#include "ssh.h"


/**
 * *add_node_end - print all elements of a lpath list
 * @head: linked list to print
 * @str: Variable char
 * Return: number of elements
 */

lpath *add_node_end(lpath **head, char *str)
{
	lpath *n;
	lpath *c;
	int a;

	n = malloc(sizeof(lpath));
	if (n == NULL)
		return (NULL);

	if (*head != NULL)
	{
		c = *head;
		for (a = 0; c->next != NULL; a++)
		{
			c = c->next;
		}
		c->next = n;
	}
	else
		*head = n;

	n->next = NULL;
	n->dir = _strdup(str);
	n->len = _strlen(str);
	return (n);
}

/**
 * free_list - print all elements of a lpath list
 * @head: linked list to print
 * Return: void
 */

void free_list(lpath *head)
{
	if (head != NULL)
	{
		free_list(head->next);
		free(head->dir);
		free(head);
	}
}
