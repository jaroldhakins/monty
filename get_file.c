#include "monty.h"
#include <stdio.h>

/**
 * get_file - tokenize and get the line
 * @path: path
 * @stack: pila
 * Return: fail or success
 **/
int get_file(char *path, stack_t **stack)
{
	FILE *fd;
	size_t size;
	ssize_t count;
	unsigned int value = 0;
	char *line = NULL;
	char *opcode;
	char *DELIM = " \n\t\r";


	if (!path)
	{
		printf("Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
	fd = fopen(path, "r");
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
	atexit(free_f);
	while ((count = getline(&line, &size, fd)) != -1)
	{
		opcode = strtok(line, DELIM);
		value++;
		if (opcode)
			list_f(stack, opcode, value);
	}
	free(line);
	fclose(fd);
	return (EXIT_SUCCESS);
}
