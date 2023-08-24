#include "monty.h"

/**
 * main - Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument values
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;

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
        /* Parse line to get opcode and arguments */
        /* Execute opcode function */
    }

    free(line);
    fclose(file);
    return EXIT_SUCCESS;
}

