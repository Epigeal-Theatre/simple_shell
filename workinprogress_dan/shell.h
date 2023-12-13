#ifndef SHELL_H
#define SHELL_H




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/*cmd chains*/
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


/*converters() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/*buf size*/
#define READ_BUF_SIZE 1024
#define wbf 1024
#define BUF_FLUSH -1

/* getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096




/*00_shellcontenthandlers.c*/
/*01_batch1builtins.c*/
/*02_batch2builtins.c*/
/*03_batch1errors.c*/
/*04_batch2errors.c*/
/*05_exit.c*/
/*06_getline.c*/
/*07_getenvironment.c*/
/* 08_fetchinfo.c*/
/*09_batch1list.c*/
/*10_batch2list.c*/
/*11_batch1str.c*/
/**/
/*13_hist.c*/
/*14_mem.c*/
/*15_parse.c*/
/*16_realloc.c*/
/*17_token.c*/
/*atoi.c*/
/*environment.c*/
/**/
/**/






#endif
