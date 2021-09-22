#include "monty.h"
/**
 * get_file -
 * 
 */
int get_file(char *pathname, stack_t **stack)
{
	FILE *fd;
	char *line = NULL;
	int count;
	size_t size;
	char *DELIM = " \t\n\r";
	char *word;
	int num_lines = 0;

	fd = fopen(pathname, "r");
	while ((count = getline(&line, &size, fd)) != -1)
	{
		word = strtok(line, DELIM);
		num_lines++;
		printf("%s\n", word);
		printf("%i\n", num_lines);
		list_f(stack, word, num_lines);
	}
	free(line);
	fclose(fd);
	return (EXIT_SUCCESS);
}
