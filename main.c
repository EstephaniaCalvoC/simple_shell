#include "ssh.h"

char **get_array(char *line)
{
	const char limit[] = " ";
	int i;/*Runer*/
	int contsp = 0;/*Counter limit*/
	char **array = NULL;

	/*Count limit char*/
	for(i = 0 ; line[i] != '\0'; i++)
	{
		if (line[i] == limit[0])
			contsp++;
	}/*Warning! case: ls              -l*/

	/*Allocate memory*/
	array = malloc(sizeof(char *) * (contsp + 2));
	if (!array)
		return (NULL);

	/*Full array*/
	array[0] = strtok(line, limit);
	if (!array[0])
	{
		free(array);
		return (NULL);
	}

	for(i = 1; i <= contsp; i++)
	{
		array[i] = strtok(NULL, limit);
		if (!array[i])
		{
			free(array);
			return (NULL);
		}
	}
	array[i] = NULL;
	return (array);
}

/**
 * execute - Execute a command indicate in a string.
 * @line: Command
 * Return: 0 if succes or -1 if fork fail.
 */
int execute(char *line)
{
	char **av = NULL;/*Command arguments*/
	char *path = NULL;/*Complet command*/
	pid_t child_pid;
	int status, n_return = 0;

	av = get_array(line);
	path = _getpath(av);

	/*Verify acces to command*/
	if (!av || !path || (access(path, F_OK) == -1))
	{
		if (errno == EACCES)
			return (prt_error(av, 126));
		else
			return (prt_error(av, 127));
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error child:");
		return (1);
	}

	if (child_pid == 0)
	{
		execve(path, av, environ);
		if (errno == EACCES)
			n_return = prt_error(av, 126);
		_exit(n_return);
	}
	else
	{
		wait(&status);
		n_return = WEXITSTATUS(status);
	}
	free(path);
	free(av);
	return (n_return);
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
	int n_return = 0;
	FILE *fp = fopen(argv[1], "r");

	ex_name = argv[0];

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
		        n_return = execute(line);
			free(line);
			line = NULL;
		}
	}

	free(line);
	return (n_return);
}
