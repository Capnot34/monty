#include "monty.h"

/**
 * pall - prints all values on the stack.
 * @stack: double pointer to the beginning of the stack.
 * @line_number: script line number.
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

