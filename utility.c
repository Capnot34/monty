#include "monty.h"

/**
 * malloc_error - prints malloc error message and exits
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
/**
 * free_stack - frees a stack_t list
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current;

	while (*stack)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}
/**
 * is_valid_int - checks if a string represents a valid integer
 * @str: the string to check
 *
 * Return: 1 if string is a valid integer, 0 otherwise
 */
int is_valid_int(const char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
