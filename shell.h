#ifndef SHELL_H
#define SHELL_H

#include "main.h"

/* String functions */
int _strcmp(const char *s1, const char *s2);
char *_strchr(const char *str, char c);
char *_strrchr(const char *str, int c);
char *_strncat(char *s1, const char *s2, size_t n);
char *_strcat(char *str, const char *cat);

/* File path functions */
char *_basename(const char *str);
int _strlen(const char *s);
char *_strncpy(char *dest, const char *src, size_t n);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, const char *src);

#endif /* SHELL_H */
