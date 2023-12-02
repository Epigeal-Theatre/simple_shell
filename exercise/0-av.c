#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 1;
	
	while (i < argc)
	{
		printf("%s", argv[i]);
		if (i < argc-1)
			putchar(' ');
		i++;
	}
	putchar('\n');
	return (0);
}
