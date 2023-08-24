#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: double pointer to the beginning of the stack.
 * @line_number: script line number.
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
    int n;
    stack_t *new;

    /* Assuming that the format of the command is: push 3 */
    /* We need to check if the next token after 'push' is a number. If not, it's an error */

    /* Let's get the number after "push" opcode. 
       You'll need to implement a function or logic to get this value. */
    n = get_value();

    /* Create new node */
    new = malloc(sizeof(stack_t));
    if (!new)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    
    new->n = n;
    new->prev = NULL;
    new->next = (*stack);
    if (*stack)
        (*stack)->prev = new;
    *stack = new;
}
