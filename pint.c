#include "monty.h"
/**
 * pint - prints the top
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
