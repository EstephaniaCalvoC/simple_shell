#include "ssh.h"

/**
 * execute - Execute a command indicate in a string.
 * @line: Command
 * Return: 0 if succes or -1 if fork fail.
 */
int execute(char *ex_name, char *line)
{
	char *argv[4] = {NULL, NULL, NULL, NULL};
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (child_pid == 0)
	{
		argv[0] = line;
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(ex_name);
			exit(98);
		}
	}
	else
	{
		wait(NULL);
	}
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

	while (1)
	{
		/*If is interactive mode*/
		if(isatty(STDIN_FILENO))
			prt_stdo("#cisfun$ ");

		n_chars = getline(&line, &len, stdin);
		if (n_chars == -1)
		{
			if(isatty(STDIN_FILENO))
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
