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
			return (value);
		}
		i++;
	}
	/*If value isn't found*/
	return (NULL);
}

/**
 * _getpath - Search a value of an enviroment variable.
 * @name: Name of enviroment variable.
 * Return: A pointer to the value.
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
	       printf("La variable PATH no fue encontrada\n");
	       return(NULL); /* pend check */
	}
	word = strtok(value, ":");
	for (; word;)
	{
		add_node_end(&head, word);
		word = strtok(NULL, value);
	}
	return (head);
}

char *_getpath(char **argv)
{
	lpath *head_path = NULL, *temp = NULL;
	char *path = NULL;
	struct stat *buf;
	int count = 0, len = 0;

	if (stat(argv[0], buf) == 0)
	{
		printf("%s was found.\n", argv[0]);
		return (argv[0]);
	}

	head_path = _create_path();
	if (head_path == NULL)
		return (NULL);

	len = _strlen(argv[0]);
	for (temp = head_path; temp != NULL; temp = temp->next)
	{
		path = malloc(sizeof(char) * (temp->len + len + 1));
		if (!path)
		{
			printf("PATH malloc fails.\n");
			free_list(head_path);
			return(NULL);
		}
		_strcat(path, "/");
		_strcat(path, temp->dir);
		if (stat(path, buf) == 0)
		{
			printf("%s was found.\n", path);
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
