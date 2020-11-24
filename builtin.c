#include "ssh.h"

/**
 * b_exit - exit function buitlin
* @av: Array of command arguments.
* @l_ret: int variable
* Return: exit error
*/

int b_exit(char **av, int *l_ret)
{
	char *line = av[0];
	int ac = 0;
	int bn = 1;/*Boolean to identify if is a number*/
	int i;/*Runner*/
	int n_return = 0;

	for (; av[ac]; ac++)
		;

	if (ac > 2)
	{
		for (i = 0; (bn == 1) && (av[1][i] != '\0'); i++)
		{
			if (av[1][i] < '0' || av[1][i] > '9')
			{
				bn = 0;
			}
		}
		if (bn == 1)
		{
			n_return = atoi(av[1]);
		}
		else
		{
			n_return = 2;
		}
	}
	else if (ac == 1)
	{
		if (*l_ret != 127 && *l_ret != 126 && *l_ret)
			n_return = 128 + *l_ret;
		else
			n_return = *l_ret;
	}
	free(av);
	free(line);
	exit(n_return);
}
