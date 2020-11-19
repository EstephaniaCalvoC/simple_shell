#include "ssh.h"

/**
 * _getenv - Search a value of an enviroment variable.
 * @name: Name of enviroment variable.
 * Return: A pointer to the value.
 */

char *_getenv(char *name)
{
	unsigned int i = 0;/*Runner*/
	char *value = NULL;
	int b = 1;/*Boolean True = 0*/
	unsigned int len = 0;

	if (!name)
		return (NULL);

	len = _strlen(name);

	while (environ[i] != NULL)
	{
		/*Compare*/
		b = strncmp(environ[i], name, len);
		/*If value if found*/
		if (b == 0)
		{
			value = environ[i] + len + 1;
			value = strdup(value);
			if (value)
				return (value);
			else
				return (NULL);
		}
		i++;
	}
	/*If value isn't found*/
	return (NULL);
}

/**
 * _create_path - Create a linked list with the directories of the path.
 * Return: A pointer to the head of the list.
 */
lpath *_create_path(void)
{
	char *value = NULL;
	char *word = NULL;
	lpath *head = NULL;
	int i = 0;/*Runner*/

	value = _getenv("PATH");
	if (!value)
	{
	       return(NULL); /* pend check */
	}

	/*Fill list*/
	word = strtok(value, ":");
	for (; word;)
	{
		add_node_end(&head, word);
		word = strtok(NULL, ":");
	}
	free(value);
	return (head);
}

char *_getpath(char **argv)
{
	lpath *head_path = NULL, *temp = NULL;
	char *path = NULL;
	struct stat buf;
	int count = 0, len = 0;

	/*If the input is a complete path*/
	if (stat(argv[0], &buf) == 0)
	{
		path = strdup(argv[0]);
		return (path);
	}

	/*If the path is not complete*/
	len = _strlen(argv[0]);

	head_path = _create_path();
	if (head_path == NULL)
		return (NULL);

	for (temp = head_path; temp != NULL; temp = temp->next)
	{
		path = malloc(sizeof(char) * (temp->len + len + 2));
		if (!path)
		{
			free_list(head_path);
			return(NULL);
		}
		strcpy(path, temp->dir);
		strcat(path, "/");
		strcat(path, argv[0]);

		if (stat(path, &buf) == 0)
		{
			free_list(head_path);
			return (path);
		}
		else
		{
			free(path);
			path = NULL;
		}
	}
	free_list(head_path);
	return (NULL);
}
