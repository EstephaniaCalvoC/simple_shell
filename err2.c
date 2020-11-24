#include "ssh.h"

/**
 * err2_exit - Creates an error message for the error number \
2 from exit function.
* @av: Array of command arguments.
* Return: A string with the error message.
*/
char *err2_exit(char **av)
{
        char *error;
        int len;

        len = _strlen(ex_name) + _strlen(av[0]) + _strlen(av[1]) + 21;
        error = malloc(sizeof(char) * (len + 1));
        if (!error)
                return (NULL);

        _strcpy(error, ex_name);
        _strcat(error, ": ");
        _strcat(error, av[0]);
        _strcat(error, ": Illegal number: ");
	_strcat(error, av[1]);
	_strcat(error, "\n");

        return (error);
}
