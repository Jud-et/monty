#include "monty.h"

/**
 * exe - function that executes a line
 * @line: the line that will be executed
 * @stack: the stack
 */

void exe(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	char *value;
	int i;

	if (strcmp(line, "") == 0)
		return;

	opcode = strtok(line, " \n\t\r");

	if (opcode == NULL)
		return;

	value = strtok(NULL, " \n\t\r");
	i = _isdigit(value);

	if ((value == NULL || i == 0) && strcmp(opcode, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	_get(line, opcode, stack, line_number);
}
