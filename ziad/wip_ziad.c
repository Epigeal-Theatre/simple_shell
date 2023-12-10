#include "shell.h"

#define PROMPT "input name of program ->"
#define ERR_NOTFOUND "Error: file or command not found\n"

/**
 * main -	simple shell program
 * Return:	0 at success.
 */
int main(void)
{
	int i = 0, exe_return, wstatus, child_pid;
	size_t read_bytes = 1024;
/*	struct stat st;*/
	char delim[] = " ";
	char *str_buf = NULL, *token = NULL, *arg_buf[5], *exe_path = NULL;

	while (1)
	{
		/* printing the prompt */
		write(1, PROMPT, strlen(PROMPT));

		/* accepting input into a string buffer */
		getline(&str_buf, &read_bytes, stdin);
		str_buf[strlen(str_buf) - 1] = '\0';

		printf("\ngetline worked and read: %s\n\n", str_buf);
		/* tokenizing the string so it turns into an array of arguments */
		token = strtok(str_buf, delim);
		printf("the first strtok worked and accepted: %s\n\n", token);
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
		exe_path = malloc(strlen(token));
		strcpy(exe_path, token);
		printf("exe_path = %s\n\n", exe_path);

		/* creating an argument array by tokenizing the input string */
		while (token != NULL)
		{
			printf("[1] token = %s\narg_buf[i] = %s\ni = %i\n",
					token, arg_buf[i], i);
			arg_buf[i] = token;
			printf("[2] token = %s\narg_buf[i] = %s\ni = %i\n",
					token, arg_buf[i], i);
			token = strtok(NULL, delim);
			printf("[3] token = %s\narg_buf[i] = %s\ni = %i\n",
					token, arg_buf[i], i);
			i++;
		}
		arg_buf[i + 1] = NULL;

		for (i = 0; arg_buf[i]; i++)
			printf("strtok() worked and read: %s\n", arg_buf[i]);

		/* freeing str_buf since we copied its tokens into arg_buf */
		free(str_buf);

		/* forking to execute the program */
		child_pid = fork();
		if (child_pid == 0)
		{
			printf("child process start\n\n");
			printf("arg_buf = %s\n\n", arg_buf[0]);
			exe_return = execvp(exe_path, arg_buf);
			if (exe_return == -1)
				perror("Error: ");
		}
		else
		{
			wait(&wstatus);
			printf("child process end and now in shell\n");

			/*freeing exe_path since execution is over*/
			free(exe_path);
		}
	}
}
