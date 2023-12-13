#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
/*	int i;
*/	(void) ac;
	(void) av;

	printf("environ: %d\nenv: %d\n", **environ, **env);
	
	return (0);
}
