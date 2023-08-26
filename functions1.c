#include "monty.h"

/**
 * push - function that pushes a value to the stack
 * @stack: stack
 * @line_number: line number
 * @value: value to be pushed
 */
void push(stack_t **stack, unsigned int line_number, char *value)
{
	int x;

	if (value == NULL || !isdigit(*value) && *value != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	x = atoi(value);

	stack_t *node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	node->n = x;
	node->prev = NULL;
	node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
}

/**
 * pall - prints all values on the stack
 * @stack: stack
 * @line_number: line number
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * err_push - prints error message if push isn't found
 * @opcode: opcode
 * @line_number: line number
 */
void err_push(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
}

/**
 * free_stack - frees the stack
 * @stack: stack to be freed
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

