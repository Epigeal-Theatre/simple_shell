#include "shell.h"

#define PROMPT "input name of program ->"

/**
 * main -	simple shell program
 * Return:	0 at success.
 */
int main(void)
{
	int read_bytes = 1024, i = 0, exe_return, wstatus;
	int shell_pid = getpid() , child_pid;
	char delim[] = " "
	char *str_buf; 
	char *token;
	char *arg_buf[1024];	/* how many arguments? how to make it flexible? */
	
	while (1)
	{
		/* printing the prompt */
		write(1, PROMPT, strlen(PROMPT));

		/* accepting input into a string buffer */
		getline(&str_buf, &read_bytes, stdin);

		/* tokenizing the string so it turns into an array of arguments */
		token = strtok(str_buf, delim);
		while (token)
		{
			strcpy(arg_buf[i], token);
			token = strtok(NULL, delim);
			i++;
		}
		arg_buf[i] = NULL;

		/* if the user wants to exit the shell */
		if (arg_buf[0] == "exit")
		{
			free(str_buf);
			return (0);
		}

		/* forking to execute the program */
		child_pid = fork();
		if (child_pid == 0)
		{
			exe_return = execve(arg_buf[0], arg_buf[1]); 
	/*how to pass arguments to the program? is an array the right way? */
			if (exe_return == -1)
			{
				perror("Error: ");
				exit(-1);
			}
		}
		else
		{
			wait(&wstatus); /* revise this */
		}

		free(str_buf);
	}
}
