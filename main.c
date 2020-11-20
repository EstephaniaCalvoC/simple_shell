#include "ssh.h"

char **get_array(char *line)
{
	const char limit[2] = " ";
	int i;/*Runer*/
	int contsp = 0;/*Counter limit*/
	char **array = NULL;

	/*Count limit char*/
	for(i = 0 ; line[i] != '\0'; i++)
	{
		if (line[i] == limit[0])
			contsp++;
	}

	/*Allocate memory*/
	array = malloc(sizeof(char *) * (contsp + 2));

	/*Full array*/
	array[0] = strtok(line, limit);

	for(i = 1; i <= contsp; i++)
	{
		array[i] = strtok(NULL, limit);
	}
	array[i] = NULL;
	return (array);
}

/**
 * execute - Execute a command indicate in a string.
 * @line: Command
 * Return: 0 if succes or -1 if fork fail.
 */
int execute(char *ex_name, char *line)
{
	char **argv = get_array(line);
	pid_t child_pid;
	char *path = NULL;

	path = _getpath(argv);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (child_pid == 0)
	{
		if (execve(path, argv, NULL) == -1)
		{
			perror(ex_name);
			exit(98);
		}
	}
	else
	{
		wait(NULL);
	}
	free(path);
	free(argv);
	return (0);
}

/**
 * main - Super simple shell.
 * Return: 0 in succes.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	int n_chars = 0;
	int file = 0;
	FILE *fp = fopen(argv[1], "r");

	if (!fp && argc > 1)
	{
	        fprintf(stderr, "Error opening file '%s'\n", argv[1]);
		return (-1);
	}
	else if (argc == 1)
		fp = stdin;

	while (1)
	{
		/*If is interactive mode*/
		if(isatty(STDIN_FILENO) && fp == stdin)
			prt_stdo("#cisfun$ ");
		n_chars = getline(&line, &len, fp);

		if (n_chars == -1)
		{
			if(isatty(STDIN_FILENO) && fp == stdin)
				prt_stdo("\n");
			break;
		}
		else if (*line != '\n')
		{
			line[n_chars - 1] = '\0';
		        execute(argv[0], line);
			free(line);
			line = NULL;
		}
		}

	free(line);

	return (0);
}
