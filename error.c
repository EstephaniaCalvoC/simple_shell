#include "ssh.h"

/**
 * err127 - Creates an error message for the error number \
127.
* @av: Array of command arguments.
* @str_hist: Array with the history number.
* Return: A string with the error message.
*/
char *err127(char **av, char *str_hist)
{
	char *error = NULL;
	int len;

	len = _strlen(ex_name) + _strlen(av[0]) + _strlen(str_hist) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
		return (NULL);

	_strcpy(error, ex_name);
	_strcat(error, ": ");
	_strcat(error, str_hist);
	_strcat(error, ": ");
	_strcat(error, av[0]);
	_strcat(error, ": not found\n");

	return (error);
}

/**
 * err126 - Creates an error message for the error number 126.
 * @av: Array of command arguments.
 * @str_hist: Array with the history number.
 * Return: A string with the error message.
 */
char *err126(char **av, char *str_hist)
{
	char *error;
	int len;

	len = _strlen(ex_name) + _strlen(av[0]) + _strlen(str_hist) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
		return (NULL);

	_strcpy(error, ex_name);
	_strcat(error, ": ");
	_strcat(error, str_hist);
	_strcat(error, ": ");
	_strcat(error, av[0]);
	_strcat(error, ": Permission denied\n");

	return (error);
}

/**
 * count_dig - Count amount of digits
 * @num: Number
 * Return: Number of digits
 */
unsigned int count_dig(int num)
{
	unsigned int i = 0;

	for (; num > 0; i++)
		num = num / 10;

	return (i);
}

/**
 * str_num - Create a string of a number
 * @n: Number
 * Return: A string
 */
char *str_num(int n)
{
	unsigned int l_dig = count_dig(n);
	char *strn = NULL;
	int num = n;

	strn = malloc(sizeof(char) * (l_dig + 1));

	strn[l_dig] = '\0';

	l_dig--;
	do {
		strn[l_dig] = (num % 10) + '0';
		num /= 10;
		l_dig--;
	} while (num > 0);
	return (strn);
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
	char *str_hist = NULL;

	str_hist = str_num(hist);

	/*Get message*/
	switch (n_error)
	{
	case 126:
		msg_err = err126(av, str_hist);
		break;
	case 127:
		msg_err = err127(av, str_hist);
		break;
	case 2:
		if (!(_strcmp(av[0], "exit")))
			msg_err = err2_exit(av, str_hist);
		break;
	}

	/*Print error message*/
	prt_stde(msg_err);

	if (str_hist)
		free(str_hist);

	if (msg_err)
		free(msg_err);

	return (n_error);
}
