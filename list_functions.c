#include "monty.h"
/**
 * list_f - redirect to fucntion to use
 * @stack: struct of the stack
 * @word: command word
 * @num_lines: number of the line
 * Return: nothing
 */
void list_f(stack_t **stack, char *word, unsigned int num_line)
{
	int i = 0;

	instruction_t ops[] = {
		{"push", push_f},
		{"pall", pall_f},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(word, ops[i].opcode) == 0)
		{
			ops[i].f(stack, num_line);
			return;
		}
	}
}