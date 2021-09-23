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
/**
 * pint_f - prints value at top of stack
 * @stack: pila
 * @value: node value
 * Return: nothing
 */
void pint_f(stack_t **stack, unsigned int value)
{
	if (*stack == NULL)
	{
		printf("L%i: can't pint, stack empty\n", value);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_f - Delete value at top of stack
 * @stack: pila
 * @value: node value
 * Return: nothing
 */
void pop_f(stack_t **stack, unsigned int value)
{
	stack_t *node;

	node = *stack;
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", value);
		exit(EXIT_FAILURE);
	}
	if (node->next != NULL)
		node->next->prev = NULL;
	*stack = (*stack)->next;
	free(node);
}

/**
 * swap_f - swaps the top two elements of the stack.
 * @stack: pila
 * @value: node value
 * Return: nothing
 */
void swap_f(stack_t **stack, unsigned int value)
{
	stack_t *temp;

	if (len_f(*stack) < 2)
	{
		printf("L%d: can't swap, stack too short\n", value);
		free_stack_f(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}
