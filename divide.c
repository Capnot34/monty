#include "monty.h"

/**
 * divide - divides the second top element by the top element of the stack.
 * @stack: double pointer to the stack.
 * @line_number: line number.
 *
 * Return: void.
 */
void divide(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    /* Check if the stack has less than two elements */
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Check for division by zero */
    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Divide the second top element by the top element */
    (*stack)->next->n /= (*stack)->n;

    /* Remove the top element */
    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}
