#include "shell.h"

/**
 * exitfunc - this function will exit shell
 *
 * @info: Structure containing arguments
 *
 *  Return: exits with a given exit status
 *	(0) if info.argv[0] != "exit"
 */

int exitfunc(info_t *info)
{
	int exitche;

	if (info->argv[1])
	/*we want to see if there is another argument after exit*/

	{
	exitche = _erratoi(info->argv[1]);
	/*we want to convert second str to int for storage*/
	if (exitche == -1)/*-1 shows error*/

	{
	info->status = 2;/*magnification of error above*/
	printerror(info, "Illegal number: ");/*communication of error above*/
	_eputs(info->argv[1]);/*print illegal exit argument*/
	_eputchar('\n');/*print new line*/
	return (1);/*return 1 to show error during exit*/
	}

	info->err_num = _erratoi(info->argv[1]);/*successful exit with no error*/
	return (-2);
	}

	info->err_num = -1;/*no exit argument*/
	return (-2);
}

/**
 * cdfunc - this function changes directory
 *
 * @info: this is a structure containing arguments
 *
 *  Return:  0
 */
int cdfunc(info_t *info)
{
	char *sz, *dir, buffer[1024];
	int chdir_ret;
/*get the current working dir and store in s*/
	sz = getcwd(buffer, 1024);
	if (!sz)/*check if getcwd failed*/
	_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])/*we want to check if no arguments were supplied*/
	{
	dir = getenvt(info, "HOME=");/*we want to get home dir from env variables*/
	if (!dir)
	chdir_ret = chdir((dir = getenvt(info, "PWD=")) ? dir : "/");
	/*if home dir isnt found, we set it to current wdir*/
	else
	chdir_ret = chdir(dir);
	}
	else if (strcomp(info->argv[1], "-") == 0)
/*if "-" is provided, we print precious directory and go there*/
	{
	if (!getenvt(info, "OLDPWD="))
	{
	_puts(sz);
	_putchar('\n');
	return (1);
	}
	_puts(getenvt(info, "OLDPWD=")), _putchar('\n');
	chdir_ret = chdir((dir = getenvt(info, "OLDPWD=")) ? dir : "/");
	}
	else
	chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
	printerror(info, "can't cd to ");
	_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
	_setenv(info, "OLDPWD", getenvt(info, "PWD="));
	_setenv(info, "PWD", getcwd(buffer, 1024));
	} /*we finally check if we succeeded at changing work dir*/
	return (0);/*shows success*/
}
/**
 * helpme - this func provides help in shell when called
 *
 * @info: this is a tructure having args
 *
 *  Return: 0
 */
int helpme(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;

	_puts("your help call works but we cant help. ask DENIS RITCHIE 4 help \n");
	if (0)

	_puts(*arg_array);

	return (0);
/*this function is supposed to provide help but we wont do that*/
}

