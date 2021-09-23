#include "monty.h"
/**
 * main - main function
 * @ac: arguments
 * @av: array
 * Return: success or failure
 **/
int main(int ac, char **av)
{
	stack_t *stack;

	initialize(&stack);
	get_file(av[1], &stack);
	exit(EXIT_SUCCESS);
	(void)ac;
}
