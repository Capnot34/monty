#include "monty.h"

/**
 * pint - prints the value at the top of the stack.
 * @stack: double pointer to the stack.
 * @line_number: line number.
 *
 * Return: void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    /* Check if the stack is empty */
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    
    /* Print the top value */
    printf("%d\n", (*stack)->n);
}
