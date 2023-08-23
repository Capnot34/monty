#include "monty.h"
/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack's top element.
 * @line_number: Line number where push is called.
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value = line_number;

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)

{
	fprintf(stderr, "Memory allocation failed\n");
	exit(EXIT_FAILURE);
}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * copyStack - Copies the contents of one stack to another.
 * @source: Source stack to be copied.
 * @destination: Destination stack to copy into.
 */

void copyStack(stack_t **source, stack_t **destination)
{
	stack_t *current = *source;

	while (current)
{
	push(destination, current->n);
	current = current->next;
}
}
/**
 * printStack - Prints the values of a stack.
 * @stack: Pointer to the stack's top element.
 * @line_number: Line number where printStack is called.
 */
void printStack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current)
{
	printf("%d\n", current->n);
	current = current->next;
}
}
