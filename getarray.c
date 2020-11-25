#include "ssh.h"

/**
 * count_lim - Count amount of a char separtor in a string.
 * @line: String whit the line of commands.
 * @limit: Separator.
 * Return: Number of separtations.
 */
unsigned int count_lim(char *line, const char *limit)
{
	int i;/*Runer*/
	int contsp = 0;/*Counter limit*/
	int csp;/*Consecutive limit*/

	for (i = 0 ; line[i] != '\0'; i++)
	{
		for (csp = 0; line[i] == limit[0]; i++)
			csp++;
		if (line[i] != '\0' && csp > 0 && (i - 1) > csp)
		{
			contsp++;
			i--;
		}
	}
	return (contsp);
}

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
	char **array = NULL;

	/*Count limit char*/
	contsp = count_lim(line, limit);
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
