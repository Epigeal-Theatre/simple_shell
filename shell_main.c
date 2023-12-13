#include "shell.h"

#define PROMPT "input name of program ->"
#define ARG_LIMIT 10
#define ERR_NOTFOUND "Error: file or command not found\n"

/**
 * main -	simple shell program
 * Return:	0 at success.
 */
int main(void)
{
	int i = 0, exe_return, wstatus, child_pid;
	size_t read_bytes = 1024;
/*	ssize_t read = 0;*/
/*	struct stat st;*/
	char delim[] = " ";
	char *str_buf = NULL, *token = NULL, *arg_buf[ARG_LIMIT], *exe_path = NULL;

	while (1)
	{
		write(1, PROMPT, strlen(PROMPT));

		getline(&str_buf, &read_bytes, stdin);

		if (str_buf[strlen(str_buf) - 1] == '\n')
			str_buf[strlen(str_buf) - 1] = '\0';

		token = strtok(str_buf, delim);
		if (strcmp(token, "exit") == 0)
			exit(EXIT_SUCCESS);

		exe_path = malloc(strlen(token) + 1);
		if (exe_path == NULL)
			errorandfree(str_buf, NULL);

		strcpy(exe_path, token);

		i = 0;
		while (token != NULL && i < ARG_LIMIT)
		{
			arg_buf[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		arg_buf[i] = NULL;

		child_pid = fork();
		if (child_pid == -1)
			errorandfree(str_buf, exe_path);

		if (child_pid == 0)
		{
			exe_return = execvp(exe_path, arg_buf);
			if (exe_return == -1)
				errorandfree(exe_path, str_buf);
		}
		else
		{
			wait(&wstatus);
			free(exe_path);
			free(str_buf);
		}
	}
}

/**
 * errorandfree -	prints error message and frees 2 buffers.
 * @buf1:		first buffer.
 * @buf2:		second buffer(can be NULL).
 * return:		nothing.
 */
void errorandfree(char *buf1, char *buf2)
{
	perror("Error: ");
	free(buf1);
	if (buf2)
		free(buf2);
	exit(EXIT_FAILURE);
}
