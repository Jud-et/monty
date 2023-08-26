#include "monty.h"

/**
 * pop - function to pop the top element from the stack
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	stack_t *tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * swap - function to swap the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	stack_t *tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;

	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->prev = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

/**
 * add - function to add the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: the line number
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
 * nop - function that does nothing (no operation)
 * @stack: pointer to the stack
 * @line_number: the line number
 */
void nop(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
}

/**
 * _isdigit - function to check if a string represents a valid integer
 * @value: the string to check
 * Return: 1 if it's a valid integer, 0 otherwise
 */
int _isdigit(char *value)
{
	if (value == NULL)
		return (0);

	for (int i = 0; value[i]; i++)
	{
		if (i == 0 && value[i] == '-')
			continue;
		if (!isdigit(value[i]))
			return (0);
	}

	return (1);
}

