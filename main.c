#include "monty.h"

/**
 * main - Entry point
 * @argv: argument arrays
 * @argc: the number of arguments
 * Return: 0 if successful
 */

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    while (fgets(line, sizeof(line), fp))
    {
        line_number++;
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
        exe(line, &stack, line_number);
    }

    fclose(fp);
    free_stack(stack);

    return (EXIT_SUCCESS);
}
