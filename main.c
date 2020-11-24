#include "ssh.h"

/**
 * get_array - Get array of command arguments
 * @line: Line of command
 * Return: Array of command arguments
 */
char **get_array(char *line)
{
	const char limit[] = " ";
	int i;/*Runer*/
	int contsp = 0;/*Counter limit*/
	int csp;/*Consecutive limit*/
	char **array = NULL;

	/*Count limit char*/
	for (i = 0 ; line[i] != '\0'; i++)
	{
		//printf("Caracter: %c\n", line[i]);
		//printf("Espacios: %d\n", contsp);
		for (csp = 0; line[i] == limit[0]; i++)
			csp++;

		if (line[i] != '\0' && csp > 0 && (i - 1) > csp)
		{
			contsp++;
			i--;
		}
		/*if (line[i] == limit[0])
		  contsp++;*/
	}

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

	for (i = 1; i <= contsp; i++)
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
 * execute - Execute a builtin commands or external commands.
 * @av: Arrays of command arguments
 * Return: The return value of the builtin command or external command.
*/
int execute(char **av)
{
	int i;
	builtin b_arr[] = {
		{"exit", b_exit},
		/*{"env", b_env},*/
		/*{"cd", b_cd},*/
		{NULL, NULL}
	};

	for (i = 0; b_arr[i].fname; i++)
	{
		if (strcmp(b_arr[i].fname, av[0]) == 0)
			break;
	}

	if (b_arr[i].fun != NULL)
		return (b_arr[i].fun(av));
	return exc_ext(av);
}

/**
 * exc_ext - Execute a command indicate in a string.
 * @av: Array of command arguments
 * Return: 0 if succes or -1 if fork fail.
 */
int exc_ext(char **av)
{
	char *path = NULL;/*Complet command*/
	pid_t child_pid;
	int status, n_return = 0;

	if (av)
		path = _getpath(av);

	/*Verify acces to command*/
	if (!path)
	{
		//printf("El path es NULL");
		return (prt_error(av, 127));
	}
	if (!av || (access(path, F_OK) == -1))
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
 * @argc: Numbers of arguments.
 * @argv: Array of shell arguments.
 * Return: 0 in succes.
 */
int main(int argc, char **argv)
{
	char *line = NULL, **av = NULL;
	size_t len = 0;
	int n_chars = 0;
	int n_return = 0;
	FILE *fp = stdin;

	ex_name = argv[0];

	while (1)
	{
		/*If is interactive mode*/
		if (isatty(STDIN_FILENO) && fp == stdin)
			prt_stdo("#cisfun$ ");
		n_chars = getline(&line, &len, fp);

		if (n_chars == -1)
		{
			if (isatty(STDIN_FILENO) && fp == stdin)
				prt_stdo("\n");
			break;
		}
		else if (*line != '\n')
		{
			line[n_chars - 1] = '\0';
			av = get_array(line);
			n_return = execute(av);
			free(line);
			av = NULL;
			line = NULL;
		}
	}
	free(line);
	return (n_return);
}
