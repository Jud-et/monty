#include "monty.h"
/**
 * err_dir - the function used to call error functions
 * @opcode: opcode
 * @line_number: the number of the line
 */

void err_dir(char *opcode, unsigned int line_number)
{
	if (strcmp(opcode, "push") != 0 && line_number == 1)
	{
		fprintf(stderr, "Error: 'push' opcode not found at line %d\n", line_number);
	}
	else
	{
		fprintf(stderr, "Error: Unable to execute 'pint' opcode at line %d\n", line_number);
	}
}

/**
 * err_pint - a function which will print pint error
 */
void err_pint(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
}
