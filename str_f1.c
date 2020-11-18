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
