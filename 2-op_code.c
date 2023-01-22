#include "monty.h"



/**
  * swap - swaps the top two elements of the stack
  * @stack: head of the stack
  * @line_number: index in monty file
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp_next;

	if ((*stack == NULL) || ((*stack)->next == NULL))
		fprint_err("L%d: can't swap, stack too short\n", line_number);

	tmp = (*stack)->next;
	tmp_next = tmp->next;

	(*stack)->next = tmp_next;
	if (tmp_next != NULL)
		tmp_next->prev = (*stack);

	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
  * add - adds the top two elements of the stack
  * @stack: head of the stack
  * @line_number: line index in monty file
  */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	int n;

	if ((*stack == NULL) || ((*stack)->next == NULL))
		fprint_err("L%d: can't add, stack too short\n", line_number);

	n = (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);

	(*stack)->n += n;
}

/**
  * sub - subs the top two elements of the stack
  * @stack: head of the stack
  * @line_number: line index in monty file
  */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	int n;

	if ((*stack == NULL) || ((*stack)->next == NULL))
		fprint_err("L%d: can't sub, stack too short\n", line_number);

	n = (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);

	(*stack)->n -= n;
}


/**
  * _div - divides the seccond top element of the stack by the top element
  * @stack: top  of the stack
  * @line_number: line index in monty file
  */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	int n;

	if ((*stack == NULL) || ((*stack)->next == NULL))
		fprint_err("L%d: can't div, stack too short\n", line_number);
	n = (*stack)->n;

	if (n == 0)
		fprint_err("L%d: division by zero\n", line_number);

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);

	(*stack)->n /= n;
}

/**
  * _mul - multiplies the second top element of the stack with the top ele
  * @stack: top of the stack
  * @line_number: line index in monty file
  */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	int n;

	if ((*stack == NULL) || ((*stack)->next == NULL))
		fprint_err("L%d: can't mul, stack too short\n", line_number);
	n = (*stack)->n;

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);

	(*stack)->n *= n;
}
