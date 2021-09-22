#include "monty.h"
/**
 * main - main function
 * @argc: number of commands
 * @argv: container the commands
 * Return: success or failure
 */
int main(int argc, char** argv)
{
    stack_t *stack;

    get_file(argv[1], &stack);
    (void)argc;
    return (0);
}
