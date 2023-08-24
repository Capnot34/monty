#include "monty.h"

/**
 * pint_op - prints the value at the top of the stack.
 * @stack: double pointer to the top of the stack.
 * @line_number: line number where the instruction appears.
 * Return: nothing.
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pchar_op - prints the char at the top of the stack.
 * @stack: double pointer to the top of the stack.
 * @line_number: line number where the instruction appears.
 * Return: nothing.
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}

/**
 * pstr_op - prints the string starting at the top of the stack.
 * @stack: double pointer to the top of the stack.
 * @line_number: line number where the instruction appears.
 * Return: nothing.
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void) line_number;  // line_number is unused in this function

    while (current && current->n > 0 && current->n < 128)
    {
        printf("%c", current->n);
        current = current->next;
    }
    printf("\n");
}

