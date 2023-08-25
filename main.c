#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	tmp->prev = *stack;
	if (tmp->next)
		tmp->next->prev = tmp;
}
void process_opcode(stack_t **stack, char *opcode, char *argument,
unsigned int line_number)
{
	/* If opcode is "push" */
	if (strcmp(opcode, "push") == 0)
	{
		if (!argument || !is_valid_int(argument))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		push(stack, atoi(argument), line_number);
	}
	/* If opcode is "pall" */
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	/* If opcode is "pint" */
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	/* If opcode is "nop" */
	else if (strcmp(opcode, "nop") == 0)
	{
		/* Do nothing, continue with the next opcode */
	}
	/* If opcode is "pchar" */
	else if (strcmp(opcode, "pchar") == 0)
	{
		pchar_op(stack, line_number);
	}
	/* If opcode is "swap" */
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	/* ... Add more opcode comparisons here ... */
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Entry point for Monty interpreter
 * @argc: Argument count
 * @argv: Array of argument strings
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
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
		/* Skip leading white spaces */
		while (*line && isspace(*line))
			line++;
		/* If line is a comment or empty, skip processing */
		if (*line == '#' || *line == '\0')
			continue;
		opcode = strtok(line, " \n\t");
		argument = strtok(NULL, " \n\t");
		process_opcode(&stack, opcode, argument, line_number);
	}
	free(line);
	free_stack(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
