#ifndef SHELL_H
#define SHELL_H

#define _GNU_SOURCE
#define PROMPT "$ "
#define ARG_LIMIT 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

/* function pointers */
void errorandfree(char *buf1, char **buf2);
void successandfree(char *buf1, char **buf2);
char *_strchr(char *s, char c);
char *_strncat(char *dest, char *src, int xn);
int _strlen(char *sz);
char *_strncpy(char *dest, char *src, int xn);
int _strcmp(char *str1, char *str2);
char **tokenarray(char *str);
#endif /* ifndef SHELL_H */
