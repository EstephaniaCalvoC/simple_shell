#include "ssh.h"

/**
 * prt_stdo - Print simple string with write in the stdo.
 * @str: String to print.
 */
void prt_stdo(char *str)
{
	unsigned int s_len;

	s_len = _strlen(str);
	write(STDOUT_FILENO, str, s_len);
}

/**
 * prt_stde - Print simple string with write in the stde.
 * @str: String to print.
 */
void prt_stde(char *str)
{
	unsigned int s_len;

	s_len = _strlen(str);
	write(STDERR_FILENO, str, s_len);
}

/**
 * _atoi - Find and print the first number
 * @s: String to convert to int
 * Return: int
 */
int _atoi(char *s)
{
	int i, n, c;

	i = n = c = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == '-')
			c++;
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			while (*(s + i) >= '0' && *(s + i) <= '9')
			{
				if (n == 0)
				{
					n = (n * 10) + (*(s + i) - '0');
					n *= -1;
				}
				else
					n = (n * 10) - (*(s + i) - '0');
				i++;
			}
			if (c % 2 == 0)
				n *= -1;
			return (n);
		}
		i++;
	}
	return (0);
}
