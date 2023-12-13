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
	ssize_t read = 0;
/*	struct stat st;*/
	char delim[] = " ";
	char *str_buf = NULL, *token = NULL, *arg_buf[ARG_LIMIT], *exe_path = NULL;

	while (1)
	{
		/* printing the prompt */
		write(1, PROMPT, strlen(PROMPT));

<<<<<<< HEAD
		/* accepting input into a string buffer *//*GETLINEGETLINE*/
		getline(&str_buf, &read_bytes, stdin);
=======
		/* accepting input into a string buffer */
		read = getline(&str_buf, &read_bytes, stdin);
		printf("\nreturn of getline = %li\n", read);
		if (read == -1)
			exit(EXIT_SUCCESS);

>>>>>>> c4f17c4a69a358913048eaa3e384465daad0a2bf
		if (str_buf[strlen(str_buf) - 1] == '\n')
			str_buf[strlen(str_buf) - 1] = '\0';

		printf("\n# getline worked and read: %s\n\n", str_buf);
		/* tokenizing the string so it turns into an array of arguments */
		token = strtok(str_buf, delim);
		printf("# the first strtok worked and accepted: %s\n\n", token);
		if (!token)
		{
			free(str_buf);
			continue;
		}

		if (strcmp(token, "exit") == 0)
			exit(EXIT_SUCCESS);

		/* checking if file or command exists */
/*		if (stat(token, &st) != 0)
		{
			write(2, ERR_NOTFOUND, strlen(ERR_NOTFOUND));
			continue;
		}
*/
		/* saving path and name of program into exe_path */
		exe_path = malloc(strlen(token) + 1);
		/* checking malloc */
		if (exe_path == NULL)
		{
			perror("Error allocating memory");
			free(str_buf);
			exit(EXIT_FAILURE);
		}

		strcpy(exe_path, token);
		printf("# exe_path = %s\n\n", exe_path);

		/* creating an argument array by tokenizing the input string */
		i = 0;
		while (token != NULL && i < ARG_LIMIT)
		{
/*			printf("[1] token = %s\narg_buf[i] = %s\ni = %i\n\n",
					token, arg_buf[i], i);
*/			arg_buf[i] = token;
/*			printf("[2] token = %s\narg_buf[i] = %s\ni = %i\n\n",
					token, arg_buf[i], i);
*/			token = strtok(NULL, delim);
			printf("# token = %s\narg_buf[i] = %s\ni = %i\n\n",
					token, arg_buf[i], i);
			i++;
		}
		arg_buf[i] = NULL;

		for (i = 0; arg_buf[i]; i++)
			printf("# strtok() worked and read: %s\n", arg_buf[i]);

		/* forking to execute the program */
		child_pid = fork();
		/* checking fork */
		if (child_pid == -1)
		{
			perror("Error forking");
			free(exe_path);
			free(str_buf);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			printf("\n# child process start\n\n");
			printf("\n# testing other variables in the child process:token = %s\nchild_pid = %i\nexe_path = %s\n", token, child_pid, exe_path);
			printf("\n# arg_buf = %s\n# address = %p\n\n", arg_buf[0], &*arg_buf[0]);
 			for (i = 0; arg_buf[i]; i++)
				printf("# strtok() worked and read: %s\n", arg_buf[i]);
			exe_return = execvp(exe_path, arg_buf);
			if (exe_return == -1)
			{
				perror("Error: ");
				free(exe_path);
				free(str_buf);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&wstatus);
			printf("\n# child process end and now in shell\n\n");

			/*freeing exe_path since execution is over*/
			free(exe_path);

			/* freeing str_buf since we tokenized it into arg_buf */
			free(str_buf);
		}
	}
}
