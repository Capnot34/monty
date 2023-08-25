#include "monty.h"

/**
 * pchar_op - prints the char at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the Monty bytecode file
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
