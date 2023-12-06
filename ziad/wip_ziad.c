#include "shell.h"

#define PROMPT "input name of program ->"

/**
 * main -	simple shell program
 * Return:	0 at success.
 */
int main(void)
{
	int /*i = 0, */exe_return, wstatus;
	int /*shell_pid = getpid() ,*/child_pid;
	size_t read_bytes = 1024;
	char delim[] = " ";
	char *str_buf = NULL; 
	char *token = NULL;
	char *arg_buf[100] = {"-l", NULL};
	
	while (1)
	{
		/* printing the prompt */
		write(1, PROMPT, strlen(PROMPT));

		/* accepting input into a string buffer */
		getline(&str_buf, &read_bytes, stdin);

		printf("getline worked and read: %s\n", str_buf);

		token = malloc(strlen(str_buf) * sizeof(char));
/* tokenizing the string so it turns into an array of arguments */
		token = strtok(str_buf, delim);
		printf("the first strtok worked and accepted: %s\n\n", token);
		
/*		while (token)
		{
			strcpy(arg_buf[i], token);
			token = strtok(NULL, delim);
			i++;
		}

		arg_buf[i] = NULL;

		for (i = 0; arg_buf[i]; i++)
			printf("strtok() worked and read: %s\n", arg_buf[i]);

	*/
/* freeing str_buf since we copied its tokens into arg_buf */
	/*	free(str_buf);*/




		/* forking to execute the program */
		child_pid = fork();
		if (child_pid == 0)
		{
			printf("child process start\n");
			exe_return = execve(arg_buf[0], arg_buf, NULL); 
			if (exe_return == -1)
			{
				perror("Error: ");
				exit(-1);
			}

		}
		else
		{
			wait(&wstatus);
			printf("child process end and now in shell\n"); 
		}

	/*	free(str_buf);*/
	}
}
