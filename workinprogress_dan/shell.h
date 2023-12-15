#ifndef _SHELL_H_
#define _SHELL_H_




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


extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: no
 * @str: str
 * @next: next node ptr
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - this args carries various args
 *@arg: str generated from getline carrying args
 *@argv: strs generated ffrom arg
 *@path: str path frm curr cmd
 *@argc: arg counter
 *@line_count: counter
 *@err_num: theese are error codes for the exit()s
 *@linecount_flag: linecountflag
 *@fn: filename
 *@env: linked list local copy of environ
 *@environmt: custom environ
 *@hist: history
 *@alias: alias
 *@changedenv: when we change environment
 *@status: ret status
 *@cmd_buf: ptr address
 *@cmd_buf_type: cmd_buf type
 *@readfd: fd to read
 *@histcount:history line counter
 */




typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fn;
	list_t *env;
	list_t *hist;
	list_t *alias;
	char **environmt;
	int changedenv;
	int status;

	char **cmd_buf; /* ptr */
	int cmd_buf_type;/*type*/
	int readfd;
	int histcount;
} info_t;


#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - bltn str
 *@type: bltn cmd
 *@func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;



/*00_shellcontenthandlers.c*/
int shell(info_t *, char **);
int find_builtin(info_t *);
void findcommand(info_t *);
void fork_cmd(info_t *);

/*01_batch1builtins.c*/
int exitfunc(info_t *);
int cdfunc(info_t *);
int helpme(info_t *);

/*02_batch2builtins.c*/
int myhist(info_t *);
/*int unsetalias(info_t *, char *);*/
/*int setalias(info_t *, char *);*/
/*int printmyalias(list_t *);*/
int alias(info_t *);

/*03_batch1errors.c*/
void _eputs(char *);
int _eputchar(char);
int _putfdec(char c, int fdec);
int _putsfdec(char *str, int fdec);

/*04_batch2errors.c*/
int erratoi(char *);
void printerror(info_t *, char *);
int printdecimal(int, int);
char *convertnumber(long int, int, int);
void commentremover(char *);

/*05_exit.c*/
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/*06_getline.c*/
/*ssize_t input_buf(info_t *, char **, size_t *);*/
ssize_t get_input(info_t *);
/*ssize_t read_buf(info_t *, char *, size_t *);*/
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/*07_getenvironment.c*/
char **get_environmt(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* 08_fetchinfo.c*/
void infoclear(info_t *);
void infoset(info_t *, char **);
void infofree(info_t *, int);

/*09_batch1list.c*/
list_t *myaddnode(list_t **, const char *, int);
list_t *addnodetoend(list_t **, const char *, int);
size_t printstringlist(const list_t *);
int deleteatindex(list_t **, unsigned int);
void myfreelist(list_t **);

/*10_batch2list.c*/
size_t lengthoflist(const list_t *);
char **list2string(list_t *);
size_t printlist(const list_t *);
list_t *nodestart(list_t *, char *, char);
ssize_t getindex(list_t *, list_t *);

/*11_batch1str.c*/
int stringlength(char *);
int strcomp(char *, char *);
char *start(const char *, const char *);
char *strconcat(char *, char *);

/*12_batch2str.c*/
char *_strcpy(char *destination, char *source);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);

/*13_hist.c*/
char *fetchfilehist(info_t *info);
int writehist(info_t *info);
int readhist(info_t *info);
int histbuilder(info_t *info, char *buf, int lnct);
int renumberhist(info_t *info);

/*14_mem.c*/
int bfree(void **);

/*15_parse.c*/
int dowehavecmd(info_t *, char *);
char *duplicatechars(char *, int, int);
char *pathfinder(info_t *, char *, char *);

/*16_realloc.c*/
char *setmem(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/*17_token.c*/
char **strtowkn(char *, char *);
char **strtowkn1(char *, char);

/*18_sarvs*/
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/*atoi.c*/
int interactive(info_t *);
int isdelimiter(char c, char *);
int isalphabet(int);
int _atoi(char *);

/*environment.c*/
int envt(info_t *);
char *getenvt(info_t *, const char *);
int setenvironment(info_t *);
int unsetenvironment(info_t *);
int populatemylist(info_t *);

#endif
