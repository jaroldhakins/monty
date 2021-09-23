#include "monty.h"

/**
 * push_f - put new element in pila
 * @stack: pila
 * @value: node value
 * Return: nothing
 */
void push_f(stack_t **stack, unsigned int value)
{
	char *opcode;
	int num;
	char *DELIM = " \n\t\r";
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(NULL, DELIM);
	if (opcode == NULL || stack == NULL)
	{
		printf("L%u: usage: push integer\n", value);
		exit(EXIT_FAILURE);
	}
	num = atoi(opcode);
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (new_node->next != NULL)
		(new_node->next)->prev = new_node;
	*stack = new_node;
}

/**
 * pall_f - prints nodes in pila
 * @stack: pila
 * @value: node value
 * Return: nothing
 */
void pall_f(stack_t **stack, unsigned int value)
{
	stack_t *new_node = *stack;

	while (new_node != NULL)
	{
		printf("%d\n", new_node->n);
		new_node = new_node->next;
	}
	(void)value;
}
