#ifndef SHELL_H
#define SHELL_H

#include <libgen.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct sh - store all data related to the shell
 * @lineptr: stores read line
 * @argv: stores argument list
 * @exe: stroes path to found executables
 */
typedef struct sh
{
	char lineptr[PATH_MAX + 1];
	char *argv[PATH_MAX + 1];
	char exe[PATH_MAX + 1];
} sh_t;

/* String functions */
int _strcmp(const char *s1, const char *s2);
char *_strchr(const char *str, char c);
char *_strrchr(const char *str, int c);
char *_strncat(char *s1, const char *s2, size_t n);
char *_strcat(char *str, const char *cat);
int _strlen(const char *s);
char *_strncpy(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, const char *src);
char *_memcpy(char *dest, const char *src, int len);
void tokenizer(sh_t *shell, char *delim);

/* File path functions */
char *_basename(const char *str);
int findexe(sh_t *shell);
int isexe(const char *filename);
int pathof(sh_t *shell, const char *exe);

/* Shell functions */
void init_sh(sh_t *sh);
void shloop(sh_t *shell, char *av);
int readline(sh_t *shell);

/* Environment functions */
char *findenv(const char *name, int *offset);
char *_getenv(const char *name);

#endif /* SHELL_H */
