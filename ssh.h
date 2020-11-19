#ifndef SSH_H
#define SSH_H

/*Global Variables*/
extern char **environ;

/*Headers*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <string.h>

/**
 * struct list - Linked list of the PATH env values
 * @dir: String with the dir
 * @len: Len of the dir
 * @next: Pointer to next node
 * Description: singly linked list node for env PATH
*/

typedef struct list
{
	char *dir;
	unsigned int len;
	struct list *next;
} lpath;


/*Helpers*/
/*--str_f1*/
unsigned int _strlen(char *str);
char *_strcat(char *dest, char *src);
/*--main helpers*/
void prt_stdo(char *str);
char *_getenv(char *name);
char *_getpath(char **argv);
lpath *_create_path(void);
/*--list helpers*/
lpath *add_node_end(lpath **head, char *str);
void free_list(lpath *head);

#endif /*SSH_H*/
