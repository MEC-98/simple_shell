#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 2050
#define BUFFER_SIZE 1050

extern char **environ;
char *concat(char *N, char *spr, char *val);
char **splitstr(char *s, const char *del);
char *__strdup(char *s);
int __strncmp(const char *s1, const char *s2, size_t l);
int __strcmp(const char *s1, const char *s2);
int __strlen(char *c);
int __putchar(char c);
void *__realloc(void *pntr, unsigned int osize, unsigned int nsize);
void _execute(char **av);
void __puts(char *s);
int cd(char *p);

int __atoi(char *c);
void _env(char **av);
void exiit(char **av);
int __setenv(const char *N, const char *val);
int __unsetenv(const char *N);
void _setenv(char **av);
void _unsetenv(char **av);
void (*_checkbuild(char **av))(char **av);

char *__getenv(const char *N);

void freeav(char **av);

void _handler(char *buf);
/**
<<<<<<< HEAD
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
=======
 * struct pathl - PATH directories are contained in a linked list
 * @d: directory
 * @ptr: pointer to node
>>>>>>> e340eea67c36ee8577fed80cbe9283b35c2983c5
 */
typedef struct pathl
{
	char *d;
	struct pathl *ptr;
} pathl;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
=======
pathl *add_node(pathl **h, char *s);
pathl *pathlink(char *p);
void freel(pathl *h);
char *__which(char *file, pathl *h);

/**
 * struct build - identifier of funct with the appropriate built-in command
 * @N: cmd
 * @funct: execute cmd
>>>>>>> e340eea67c36ee8577fed80cbe9283b35c2983c5
 */
typedef struct build
{
	char *N;
	void (*funct)(char **);
} build;

#endif
