#include "ssh.h"

/**
 * prt_stdo - Print simple string with write in the stdo.
 * @str: String to print.
 */
void prt_stdo(char *str)
{
        ssize_t n_chars;
        unsigned int s_len;

        s_len = _strlen(str);
        n_chars = write(STDOUT_FILENO, str, s_len);
}
