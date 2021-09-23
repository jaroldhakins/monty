#include "monty.h"

vgb_t vgb;

/**
 * list_f - redirect to function
 * @stack: pila
 * @code: code operator
 * @value: value of line
 * Return: nothing
 **/
void list_f(stack_t **stack, char *code, unsigned int value)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push_f},
		{"pall", pall_f},
		{"pint", pint_f},
		{"pop", pop_f},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(code, ops[i].opcode) == 0)
		{
			ops[i].f(stack, value);
			return;
		}
	}
	if (strlen(code) != 0 && code[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", value, code);
		exit(EXIT_FAILURE);
	}
}

/**
 * initialize - initialize all the things
 * @stack: top of stack data structure
 */
void initialize(stack_t **stack)
{
	*stack = NULL;
	vgb.top = stack;
}

/**
 * free_f - free malloc
 * Return: nothing
 */
void free_f(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(vgb.top);
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
