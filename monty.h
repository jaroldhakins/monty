#ifndef _MONTY_
#define _MONTY_

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct vgb_s - globally useful variables, all rolled into one
 * @top: double pointer to top of stack
 * @ops: double pointer to an instruction struct
**/
typedef struct vgb_s
{
	stack_t **top;
	instruction_t **ops;
} vgb_t;

extern vgb_t vgb;

void initialize(stack_t **stack);
void free_f(void);
int get_file(char *path, stack_t **stack);
void list_f(stack_t **stack, char *op, unsigned int value);
void push_f(stack_t **stack, unsigned int value);
void pall_f(stack_t **stack, unsigned int value);
void pint_f(stack_t **stack, unsigned int value);
void pop_f(stack_t **stack, unsigned int value);

#endif
