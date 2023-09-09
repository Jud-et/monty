#include "monty.h"
/**
 * pop - this is the function pop
 * @stack: this is the stack
 * @line_number: the number of the line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
/**
 * swap - this is the function that swaps between two stacks
 * @stack: the stack
 * @line_number: the number of the line
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->prev = NULL;
	tmp->next = *stack;
	*stack = tmp;
}
/**
 * add - function that adds the stacks
 * @stack: the stacks to be added
 * @line_number: the number of the lin
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
/**
 * nop - this is the function nope
 * @stack: the stack to be used
 * @line_number: the number of the line
 */
void nop(__attribute__((unused)) stack_t **stack,
	__attribute__((unused)) unsigned int line_number)
{
}
/**
 * _isdigit - this is a function to show whether a string is a digit
 * Return: void
 */
int _isdigit(char *value)
{
	int i;

	if (value == NULL)
		return (0);
	for (i = 0 ; value[i] != '\0'; i++)
	{
		if (value[i] == '-' && i == 0)
			continue;
		if (!isdigit(value[i]))
			return (0);
	}

	return (1);
}
