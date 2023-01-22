#include "monty.h"

/**
  * pop - removes the top element of the stack
  * @stack: head of the stack
  * @line_number: line number where the error occured
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
  * pint - prints the value at the top of the stack
  * @stack: head of the stack
  * @line_number: line number of where the error occured
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
  * free_stack - frees the strack data structture
  * @stack: head of the stack
  */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
  * push - pushes node to stack
  * @stack: head of stack
  * @line_number: integer data type of node
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

/**
  * pall - prints all data in stack from top to bottom
  * @stack: head of stack
  */
void pall(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
