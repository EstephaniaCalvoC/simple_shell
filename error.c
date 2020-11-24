#include "ssh.h"

/**
 * err127 - Creates an error message for the error number \
127.
* @av: Array of command arguments.
* Return: A string with the error message.
*/
char *err127(char **av)
{
	char *error;
	int len;

	len = _strlen(ex_name) + _strlen(av[0]) + 14;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
		return (NULL);

	_strcpy(error, ex_name);
	_strcat(error, ": ");
	_strcat(error, av[0]);
	_strcat(error, ": not found\n");

	return (error);
}

/**
 * err126 - Creates an error message for the error number 126.
 * @av: Array of command arguments.
 * Return: A string with the error message.
 */
char *err126(char **av)
{
	char *error;
	int len;

	len = _strlen(ex_name) + _strlen(av[0]) + 22;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
		return (NULL);

	_strcpy(error, ex_name);
	_strcat(error, ": ");
	_strcat(error, av[0]);
	_strcat(error, ": Permission denied\n");

	return (error);
}

/**
 * prt_error - Print the corresponding message error according
 * to the error number.
 * @av: Array of command argurments.
 * @n_error: Error number.
 * Return: Error number.
 */
int prt_error(char **av, int n_error)
{
	char *msg_err = NULL;/*Message error*/

	/*Get message*/
	switch (n_error)
	{
	case 126:
		msg_err = err126(av);
		break;
	case 127:
		msg_err = err127(av);
		break;
	}

	/*Print error message*/
	prt_stdo(msg_err);

	if (msg_err)
		free(msg_err);

	return (n_error);
}
