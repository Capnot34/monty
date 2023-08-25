#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the stack's top
 * @n: integer value to push onto the stack
 * @line_number: line number in the Monty bytecode file
 */
void push(stack_t **stack, int n, unsigned int line_number)
{
	stack_t *new_node;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the stack's top
 * @line_number: line number in the Monty bytecode file (unused here)
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack's top
 * @line_number: line number in the Monty bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node_to_remove;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node_to_remove = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(node_to_remove);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack's top
 * @line_number: line number in the Monty bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

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
 *  rotr_op - rotates the stack to the bottom
 *  @stack: double pointer to the top of the stack
 *  @line_number: line number in the Monty bytecode file
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
