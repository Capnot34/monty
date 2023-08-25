#include "monty.h"

/**
 * handle_push - Handles the 'push' opcode
 * @stack: Double pointer to the top of the stack
 * @argument: The argument passed with the opcode
 * @line_number: Current line number
 */
void handle_push(stack_t **stack, char *argument, unsigned int line_number)
{
	if (!argument || !is_valid_int(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	push(stack, atoi(argument), line_number);
}
void handle_pall(stack_t **stack, char *argument, unsigned int line_number)
{
	(void) argument;
	pall(stack, line_number);
}
void handle_pint(stack_t **stack, char *argument, unsigned int line_number)
{
	(void) argument;
	pint(stack, line_number);
}
void handle_pchar(stack_t **stack, char *argument, unsigned int line_number)
{
	(void) argument;
	pchar_op(stack, line_number);
}
void handle_swap(stack_t **stack, char *argument, unsigned int line_number)
{
	(void) argument;
	swap(stack, line_number);
}
void handle_pop(stack_t **stack, char *argument, unsigned int line_number)
{
	(void) argument;
	pop(stack, line_number);
}
void handle_add(stack_t **stack, char *argument, unsigned int line_number)
{
	(void) argument;
	add(stack, line_number);
}
void handle_sub(stack_t **stack, char *argument, unsigned int line_number)
{
	(void) argument;
	sub(stack, line_number);
}
void handle_mul(stack_t **stack, char *argument, unsigned int line_number)
{
	(void) argument;
	mul_op(stack, line_number);
}
void handle_div(stack_t **stack, char *argument, unsigned int line_number)
{
	(void) argument;
	div_op(stack, line_number);
}
void handle_mod(stack_t **stack, char *argument, unsigned int line_number)
{
	(void) argument;
	mod_op(stack, line_number);
}
/**
 * process_opcode - Processes the given opcode
 * @stack: Double pointer to the top of the stack
 * @opcode: The opcode to process
 * @argument: The argument passed with the opcode
 * @line_number: Current line number
 */
void process_opcode(stack_t **stack, char *opcode, char *argument, unsigned int line_number)
{
	int i = 0;

	typedef struct instruction_s
	{
		char *opcode;
		void (*f)(stack_t **stack, char *argument, unsigned int line_number);
	} instruction_t;

	instruction_t ops[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pchar", handle_pchar},
		{"swap", handle_swap},
		{"pop", handle_pop},
		{"add", handle_add},
		{"sub", handle_sub},
		{"mul", handle_mul},
		{"div", handle_div},
		{"mod", handle_mod},
		{NULL, NULL}
	};
	while (ops[i].opcode)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, argument, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, 
		"L%d: unknown instruction %s\n", 
		line_number, opcode);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

