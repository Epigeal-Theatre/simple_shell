#include "shell.h"

/**
 * shell - this is the master shell call
 *
 * @info: struct placeholder
 *
 * @av: arg placeholder
 *
 * Return: 0 upon success and otherwise 1
 *
 */
int shell(info_t *info, char **av)
{
	ssize_t x = 0;
	int rtbtn = 0;

	while (x != -1 && rtbtn != -2)
	{
	infoclear(info);
	if (interactive(info))
	_puts("$ ");
	_eputchar(BUF_FLUSH);
	x = get_input(info);
	if (x != -1)
	{
	infoset(info, av);
	rtbtn = find_builtin(info);
	if (rtbtn == -1)
	findcommand(info);
	}
	else if (interactive(info))
	_putchar('\n');
	infofree(info, 0);
	}
	writehist(info);
	infofree(info, 1);
	if (!interactive(info) && info->status)
	exit(info->status);
	if (rtbtn == -2)
	{
	if (info->err_num == -1)
	exit(info->status);
	exit(info->err_num);
	}
	return (rtbtn);
}


/**
 * find_builtin - this guy finds builtins and
 * ...helps us execute them when we call
 *
 * @info: struct placeholder
 *
 * Return: -1 if we cant find the btn we called,
 *			0 if we call and executre builtin,
 *			1 if we cant execute a builtin but its there,
 *			-2 if we call the exit builtin()
 */
int find_builtin(info_t *info)
{
	int x, builtin_ret = -1;
	builtin_table builtintab[] = {
		{"exit", exitfunc},
		{"env", envt},
		{"help", helpme},
		{"history", myhist},
		{"setenv", setenvironment},
		{"unsetenv", unsetenvironment},
		{"cd", cdfunc},
		{"alias", alias},
		{NULL, NULL}
	};

	for (x = 0; builtintab[x].type; x++)
		if (strcomp(info->argv[0], builtintab[x].type) == 0)
		{
			info->line_count++;
			builtin_ret = builtintab[x].func(info);
			break;
		}
	return (builtin_ret);
}

/**
 * findcommand - this func snoops through a path for commands
 *
 * @info: struct placeholder
 *
 * Return: void
 */
void findcommand(info_t *info)
{
	char *path = NULL;
	int a, b;


	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
	info->line_count++;
	info->linecount_flag = 0;
	}
	for (a = 0, b = 0; info->arg[a]; b++)
	if (!isdelimiter(info->arg[a], " \t\n"))
	b++;
	if (!b)
	return;

	path = pathfinder(info, getenvt(info, "PATH="), info->argv[0]);
	if (path)
	{
	info->path = path;
	fork_cmd(info);
	}
	else
	{
	if ((interactive(info) || getenvt(info, "PATH=")
	|| info->argv[0][0] == '/') && dowehavecmd(info, info->argv[0]))
	fork_cmd(info);
	else if (*(info->arg) != '\n')
	{
	info->status = 127;
	printerror(info, "not found\n");
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
	perror("Error:");
	return;
	}
	if (child_pid == 0)
	{
	if (execve(info->path, info->argv, get_environmt(info)) == -1)
	{
	infofree(info, 1);
	if (errno == EACCES)
	exit(126);
	exit(1);
	}
	}
	else
	{
	wait(&(info->status));
	if (WIFEXITED(info->status))
	{
	info->status = WEXITSTATUS(info->status);
	if (info->status == 126)
	printerror(info, "Permission denied\n");
	}
	}
}
