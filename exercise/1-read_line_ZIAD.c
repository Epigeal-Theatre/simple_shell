#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int return_getline/*, return_read, fd*/;
	size_t read_size = 1024;
/*	char *read_buffer = NULL;
*/	char *getline_buffer = NULL;
	(void) argc;
	(void) argv;

	return_getline = getline(&getline_buffer, &read_size, stdin);
	printf("getline(): %s\nreturn_getline = %i\n", getline_buffer, return_getline);
/*
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-2);

	read_buffer = malloc(1024);
	if (read_buffer == NULL)
		return (-1);

	return_read = read(fd, read_buffer, 1024);
	if (return_read == -1)
		return (-3);

	printf("\nread(): %s\n, return_read = %i\n", read_buffer, return_read);

	free(read_buffer);
*/	free(getline_buffer);
	return (0);
}
