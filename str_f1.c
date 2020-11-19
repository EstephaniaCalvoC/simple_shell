#include "ssh.h"

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
 * *_strcat - prototype function
 * @dest: - Variable char pointer
 * @src: - Variable char pointer
 * Return: void
 */

char *_strcat(char *dest, char *src)
{
	int a = 0, b = 0;

	if (dest == NULL)
		dest = "";
	if (src == NULL)
		src = "";

	while (dest[a] != '\0')
		a++;

	while (src[b] != '\0')
	{
		dest[a + b] = src[b];
		b++;
	}
	return (dest);
}
