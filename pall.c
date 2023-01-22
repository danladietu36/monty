#include "monty.h"
/**
 *pall - prints all elemnts in list
 *@stack: address of list head ointer
 *@line_number:line no
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
