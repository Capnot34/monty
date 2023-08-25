#include "monty.h"

/**
 * rotl_op - rotates the stack to the top
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the Monty bytecode file
 */
void rotl_op(stack_t **stack,
unsigned int line_number __attribute__((unused)))
{
	stack_t *end;

	if (!*stack || !(*stack)->next)
		return;
	end = *stack;
	while (end->next)
		end = end->next;
	end->next = *stack;
	(*stack)->prev = end;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr_op - rotates the stack to the bottom
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the Monty bytecode file
 */
void rotr_op(stack_t **stack,
unsigned int line_number __attribute__((unused)))
{
	stack_t *end;

	if (!*stack || !(*stack)->next)
		return;
	end = *stack;
	while (end->next)
		end = end->next;
	end->prev->next = NULL;
	end->prev = NULL;
	end->next = *stack;
	(*stack)->prev = end;
	*stack = end;
}

/**
 * stack_op - does nothing (to ensure stack behavior)
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the Monty bytecode file
 */
void stack_op(stack_t **stack __attribute__((unused)),
unsigned int line_number __attribute__((unused)))
{}

/**
 * queue_op - does nothing (to ensure queue behavior)
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the Monty bytecode file
 */
void queue_op(stack_t **stack __attribute__((unused)),
unsigned int line_number __attribute__((unused)))
{}
