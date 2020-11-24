#include "ssh.h"

/**
* b_exit - exit function buitlin
* @av: Array of command arguments.
* @l_ret: Pointer to number of the last return
*/

void b_exit(char **av, int *l_ret)
{
	char *line = av[0];
	unsigned int ac = 0, bn = 1;/*Boolean to identify if is a number*/
	int n_return = 0, i;/*Runner*/

	for (; av[ac]; ac++)
		;

	if (ac >= 2)
	{
		for (i = 0; (bn == 1) && (av[1][i] != '\0'); i++)
			if (av[1][i] < '0' || av[1][i] > '9')
				bn = 0;
		if (bn == 1)
			n_return = _atoi(av[1]);
		else
			n_return = 2;/*Pending Handle error*/
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

/**
 * evn - Print the enviroment variables
 * @av: Array of arguments
 * @l_ret: Pointer to number of the last return
 */
void b_env(char **av, int *l_ret)
{
	unsigned int ac = 0, i;/*Runer*/

	for (; av[ac]; ac++)
                ;

	if (ac != 1 || !environ)
		*l_ret = 2; /*Pending- handle error*/
	else
	{
		i = 0;
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
		*l_ret = 0;
	}
}
