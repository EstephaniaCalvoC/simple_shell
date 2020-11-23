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
	int index, size;

	size = _strlen(dest);

	for (index = size; src[index - size] != '\0'; index++)
		dest[index] = src[index - size];
	dest[index] = '\0';
	return (dest);
}

/**
 * _strcpy - copy the string in src to dest with null at end,
 * @dest: destiny char
 * @src: source char
 * Return: copy char in destiny
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
