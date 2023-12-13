#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/* function pointers */
void errorandfree(char *buf1, char *buf2); 
void successandfree(char *buf1, char *buf2);
#endif /* ifndef SHELL_H */
