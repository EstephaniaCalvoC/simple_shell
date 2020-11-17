#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <string.h>

/**
 * _strlen - Count the amount of character of a string.
 * @str: String.
 * Return: Number of characters in the string.
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	if (!str)
		return (0);

	while (str[len])
		len++;

	return (len);
}

/**
 * prt_stdo - Print simple string with write in the stdo.
 * @str: String to print.
 */
void prt_stdo(char *str)
{
	ssize_t n_chars;
	unsigned int s_len;

	s_len = _strlen(str);
	n_chars = write(STDOUT_FILENO, str, s_len);
}

/**
 * execute - Execute a command indicate in a string.
 * @line: Command
 * Return: 0 if succes or -1 if fork fail.
 */
int execute(char *line)
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
			perror("Error");
			exit(98);
		}
	}
	else
	{
		wait(NULL);
		/*printf("Terminado %d\n", child_pid);*/
	}
	return (0);
}

/**
 * main - Super simple shell.
 * Return: 0 in succes.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	int n_chars = 0;

	while (1)
	{
		/*If is interactive mode*/
		/*if(isatty(STDIN_FILENO))
		  prt_stdo("#cisfun$ ");*/
		prt_stdo("#cisfun$ ");

		n_chars = getline(&line, &len, stdin);
		if (n_chars == -1)
		{
			/*prt_stdo("EXIT\n");*/
			if(isatty(STDIN_FILENO))
				prt_stdo("Ahora entra aquí\n");
			break;
		}
		else if (*line != '\n')
		{
			prt_stdo("Entra aquí\n");
			line[n_chars - 1] = '\0';
			/*prt_stdo("Ejecutar el comando ");*/
			/*prt_stdo(line);*/
			/*prt_stdo("\n");*/
			execute(line);
			free(line);
			line = NULL;
		}
	}

	free(line);

	return (0);
}
