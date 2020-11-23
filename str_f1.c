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

/**
 * _strcmp - Compare two strings.
 * @s1: string 1.
 * @s2: string 2.
 * Return: 0 if the string are the same.
 */

int _strcmp(char *s1, char *s2)
{
	for (; (*s1 != '0' && *s2 != '\0') && *s1 == *s2;)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}

/**
 * _strdup - this functions duplicate a string.
 * @str: the string to copy
 * Return: string duplicate
 **/

char *_strdup(char *str)
{
	char *strduplicate = NULL;
	int counter = 0, size = 0;

	i = 0;
	if (str == NULL)
		return (NULL);

	size = _strlen(dest) + 1;

	/* check malloc and free */
	strduplicate = malloc(size * sizeof(*str));
	if (p == NULL)
		return (NULL);

	for (; counter < size - 1; counter++)
		strduplicate[counter] = str[counter]

	strduplicate[counter] = '\0';
	return (strduplicate);
}
