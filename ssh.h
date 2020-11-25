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
char *ex_name; /*;Shell's executable name*/
int hist;/*Number of line in the shell*/

/*Structures*/

/**
 * struct list_s - Linked list of the PATH env values
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
 * struct builtin_s - A new struct type defining builtin commands.
 * @fname: The name of the builtin command.
 * @fun: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *fname;
	void (*fun)(char **av, int *l_ret);
} builtin;

/*Prototypes*/

/*Main helpers*/
/*..getarray*/
char **get_array(char *line);
unsigned int count_lim(char *line, const char *limit);
/*..execfun*/
int execute(char **av, int *l_ret);
int exc_ext(char **av);
/*..builtin*/
void b_exit(char **av, int *l_ret);
void b_env(char **av, int *l_ret);
/*..path*/
char *_getenv(char *name);
char *_getpath(char **argv);
lpath *_create_path(void);
/*..error*/
int prt_error(char **av, int n_error);
char *err126(char **av, char *str_hist);
char *err127(char **av, char *str_hist);
char *err2_exit(char **av, char *str_hist);
/*..helpers*/
void prt_stdo(char *str);
int _atoi(char *s);
void prt_stde(char *str);
/*String helpers*/
/*..str_f1*/
unsigned int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);

/*Linked list helpers*/
/*..list*/
lpath *add_node_end(lpath **head, char *str);
void free_list(lpath *head);

#endif /*SSH_H*/
