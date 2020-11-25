#include "ssh.h"

/**
 * execute - Execute a builtin commands or external commands.
 * @av: Arrays of command arguments
 * @l_ret: A pointer to number of the last return.
 * Return: The return value of the builtin command or external command.
 */
int execute(char **av, int *l_ret)
{
	int i;
	builtin b_arr[] = {
		{"exit", b_exit},
		{"env", b_env},
		{NULL, NULL}};

	for (i = 0; b_arr[i].fname; i++)
	{
		if (_strcmp(b_arr[i].fname, av[0]) == 0)
			break;
	}
	if (b_arr[i].fun != NULL)
	{
		b_arr[i].fun(av, l_ret);
		return (*l_ret);
	}
	return (exc_ext(av));
}
