#ifndef SSH_H
#define SSH_H

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

/*Helpers*/
/*--str_f1*/
unsigned int _strlen(char *str);
/*--main helpers*/
void prt_stdo(char *str);

#endif /*SSH_H*/
