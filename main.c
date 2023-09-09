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
	FILE *fp;
	char line[MAX_LINE_LENGTH];
	stack_t *stack = NULL;
	char *filename;
	unsigned int line_number = 0;
	size_t length = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	filename = argv[1];
	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		line_number++;
		length = strlen(line);

		if (length > 0 && line[length - 1] == '\n')
			line[length - 1] = '\0';

		exe(line, &stack, line_number);
	}
	fclose(fp);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
