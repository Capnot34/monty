#include "monty.h"
global_t global_vars = {STACK_MODE};

/**
 * opcode_push - handles the 'push' opcode
 * @stack: Double pointer to the top of the stack
 * @argument: Argument passed with the opcode
 * @line_number: Current line number
 */
void opcode_push(stack_t **stack, char *argument, unsigned int line_number)
{
	if (!argument || !is_valid_int(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	push(stack, atoi(argument), line_number);
}
/**
 * opcode_execute - Executes the given opcode
 * @stack: Double pointer to the top of the stack
 * @opcode: The opcode to process
 * @argument: The argument passed with the opcode
 * @line_number: Current line number
 */
void opcode_execute(stack_t **stack,
char *opcode, char *argument, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
		opcode_push(stack, argument, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
	{}
	else if (strcmp(opcode, "pchar") == 0)
		pchar_op(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
		mul_op(stack, line_number);
	else if (strcmp(opcode, "div") == 0)
		div_op(stack, line_number);
	else if (strcmp(opcode, "mod") == 0)
		mod_op(stack, line_number);
	else if (strcmp(opcode, "pstr") == 0)
		pstr_op(stack, line_number);
	else if (strcmp(opcode, "rotl") == 0)
		rotl_op(stack, line_number);
	else if (strcmp(opcode, "rotr") == 0)
		rotr_op(stack, line_number);
	else if (strcmp(opcode, "stack") == 0)
		stack_op(stack, line_number);
	else if (strcmp(opcode, "queue") == 0)
		queue_op(stack, line_number);
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
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL, *opcode, *argument;
	char *temp_line;
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

		temp_line = line;
		while (*temp_line && isspace(*temp_line))
			temp_line++;
		if (*temp_line == '#' || *temp_line == '\0')
			continue;
		opcode = strtok(temp_line, " \n\t");
		argument = strtok(NULL, " \n\t");
		opcode_execute(&stack, opcode, argument, line_number);
		free(line);
		line = NULL;
	}
	free(line);
	free_stack(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
