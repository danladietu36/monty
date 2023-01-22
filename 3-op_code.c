#include "monty.h"

/**
  * mod - computes the rest of the division
  * @stack: top of the stack
  * @line_number: line index of file
  */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	int n;

	if ((*stack == NULL) || ((*stack)->next == NULL))
		fprint_err("L%d: can't mod, stack too short\n", line_number);
	n = (*stack)->n;

	if (n == 0)
		fprint_err("L%d: division by zero\n", line_number);

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);

	(*stack)->n %= n;
}

/**
  * pchar - prints the char at the top of the stack
  * @stack: top of stack
  * @line_number: line index int filoe
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	(void)line_number;
	if (_isempty(*stack))
		fprint_err("L%d: catn't pchar, stack empty\n", line_number);

	n = (*stack)->n;
	if (!_ascii(n))
		fprint_err("L%d: can't pchar, value out of range\n", line_number);

	printf("%c\n", n);
}

/**
  * pstr - prints the string from top of stack
  * @stack: top of stack
  * @line_number: line index of file
  */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		if (tmp->n == 0)
			break;

		if (!_ascii(tmp->n))
			break;

		if (_ascii(tmp->n))
			printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
