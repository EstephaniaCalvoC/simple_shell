#ifndef SSH_H
#define SSH_H

/*Headers*/
#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#include <errno.h>

#include <stdarg.h>
#include <string.h>

/*Global Variables*/
extern char **environ;/*Environemnt*/
char *ex_name;/*Shell's executable name*/

/*Structures*/

/**
 * struct list_p - Linked list of the PATH env values
 * @dir: String with the dir
 * @len: Len of the dir
 * @next: Pointer to next node
 * Description: singly linked list node for env PATH
*/

typedef struct list_s
{
	char *dir;
	unsigned int len;
	struct list_s *next;
} lpath;

/**
 * struc bultin_b - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct bultin_s
{
	char *fname;
	int (*fun)(char **av);
} builtin;

/*Prototypes*/

/*Main helpers*/
char **get_array(char *line);
int execute(char **av);
int exc_ext(char **av);
/*..builtin*/
int b_exit(char **av);
/*..path*/
char *_getenv(char *name);
char *_getpath(char **argv);
lpath *_create_path(void);
/*..error*/
int prt_error(char **av, int n_error);
char *err126(char **av);
/*..helpers*/
void prt_stdo(char *str);

/*String helpers*/
/*..str_f1*/
unsigned int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

/*Linked list helpers*/
/*..list*/
lpath *add_node_end(lpath **head, char *str);
void free_list(lpath *head);

#endif /*SSH_H*/
