#include "monty.h"

int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL, *opcode, *argument;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL; 

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        opcode = strtok(line, " \n\t");
        argument = strtok(NULL, " \n\t");

        /* If opcode is "push" */
        if (strcmp(opcode, "push") == 0)
        {
            if (!argument || !is_valid_int(argument))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free(line);
                free_stack(&stack);
                exit(EXIT_FAILURE);
            }
           push(&stack, atoi(argument), line_number);
        }
        /* If opcode is "pall" */
        else if (strcmp(opcode, "pall") == 0)
            pall(&stack, line_number);
        /* If opcode is "pint" */
        else if (strcmp(opcode, "pint") == 0)
            pint(&stack, line_number);
        /* ... Add more opcode comparisons here ... */

        /* If opcode is not recognized */
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free(line);
            free_stack(&stack);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    free_stack(&stack); 
    fclose(file);

    return EXIT_SUCCESS;
}
