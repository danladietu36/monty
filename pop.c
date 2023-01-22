#include "monty.h"
/**
 *pop - removes element on top of stack
 *@head: pointer to pointer
 *@ln: line no
 */
void pop(stack_t **head, unsigned int ln)
{
	stack_t *temp;

	(void)ln;
	temp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
