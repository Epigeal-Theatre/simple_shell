#include "shell.h"

/**
 * main -	simple shell program
 * @ac:		argument count.
 * @av:		argument vector.
 * @env:	environment.
 * Return:	0 at success.
 */
int main(int ac, char **av, char **env)
{
	int exe_return, wstatus, child_pid;
	size_t read_bytes = 1024;
	ssize_t read = 0;
	char *str_buf = NULL, **arg_buf;
	(void) ac;
	(void) av;

	while (1)
	{
		if (isatty(0) == 1)
			write(1, PROMPT, _strlen(PROMPT));
		read = getline(&str_buf, &read_bytes, stdin);
		if (read == -1)
			successandfree(str_buf, NULL);
		if (str_buf[_strlen(str_buf) - 1] == '\n')
			str_buf[_strlen(str_buf) - 1] = '\0';
		if (!str_buf || read == 1)
		{
			fflush(stdin);
			str_buf = NULL;
			continue;
		}
		arg_buf = tokenarray(str_buf);
		child_pid = fork();
		if (child_pid == -1)
			errorandfree(str_buf, arg_buf);
		if (child_pid == 0)
		{
			exe_return = execvpe(arg_buf[0], arg_buf, env);
			if (exe_return == -1)
				errorandfree(str_buf, arg_buf);
		}
		else
		{
			wait(&wstatus);
			fflush(stdin);
			str_buf = NULL;
		}
	}
	return (0);
}
