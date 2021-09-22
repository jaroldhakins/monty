#include "monty.h"
/**
 * push_f - Add the new element to the stack
 * @stack: struct of the nodes
 * @num_line: is the number of line
 * Return: nothing
 */
void push_f(stack_t **stack, unsigned int num_line)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit;
	new->n = num_line;
	new->next = NULL;
	new->prev = NULL;
	if (*stack == NULL)
	{
		new = *stack;
	}
	(*stack)->prev = new;
	new->next = *stack;
	*stack = new;
}
/**
 * pall_f - prints all values on the stack, starting from top
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void pall_f(stack_t **stack, unsigned int num_line)
{
	stack_t *new = *stack;

	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
	(void)num_line;
}
