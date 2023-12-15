#include "shell.h"
/**
 * hsh - this is the master shell call
 *
 * @info: struct placeholder
 *
 * @av: arg placeholder
 *
 * Return: 0 upon success and otherwise 1
 *
 */

int hsh(info_t *info, char **av)
{
	ssize_t q = 0;
	int builtinret = 0;

	while (q != -1 && builtinret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		q = get_input(info);
		if (q != -1)
		{
			set_info(info, av);
			builtinret = find_builtin(info);
			if (builtinret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}

	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);

	if (builtinret == -2)

	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtinret);
}

/**
 * find_builtin - this guy finds builtins and
 * ...helps us execute them when we call
 *
 * @info: struct placeholder
 *
 * Return: -1 if we cant find the btn we called,
 *                      0 if we call and executre builtin,
 *                      1 if we cant execute a builtin but its there,
 *                      -2 if we call the exit builtin()
 */

int find_builtin(info_t *info)
{
	int x, br = -1;
	builtin_table builtintab[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (x = 0; builtintab[x].type; x++)

		if (_strcmp(info->argv[0], builtintab[x].type) == 0)
		{

			info->line_count++;
			br = builtintab[x].func(info);
			break;
		}

	return (br);
}

/**
 * find_cmd - this func snoops through a path for commands
 *
 * @info: struct placeholder
 *
 * Return: void
 */

void find_cmd(info_t *info)
{
	char *path = NULL;
	int x;
	int l;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (x = 0, l = 0; info->arg[x]; x++)
		if (!is_delim(info->arg[x], " \t\n"))
			l++;

	if (!l)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}


/**
 * fork_cmd - this guy will fork a process to run commands
 *
 * @info: struct placeholder
 *
 * Return: return void
 */



void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{

		/* error func*/
		perror("Error:");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* error func goes here */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
