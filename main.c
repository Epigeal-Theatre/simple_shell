#include "shell.h"
/**
 * main - this is the main entry
 *
 * @ac: arg ct
 *
 * @av: placeholder for arg vector
 *
 * Return: 0 oupon success or otherwise 1
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };

	int xfd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=q" (xfd)
		: "q" (xfd));

	if (ac == 2)
	{
		xfd = open(av[1], O_RDONLY);
		if (xfd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = xfd;
	}
	populate_env_list(info);

	read_history(info);

	hsh(info, av);
	return (EXIT_SUCCESS);
}
