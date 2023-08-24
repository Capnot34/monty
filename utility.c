#include "monty.h"

void malloc_error(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
}

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

