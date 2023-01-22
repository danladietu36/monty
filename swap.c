#include "monty.h"
/**
 *swap - swaps first and second items on stack
 *@head: pointet to pinyer to head
 *@ln: line no
 */
void swap(stack_t **head, unsigned int ln)
{
	int count = 0;
	stack_t *temp;

	(void)ln;
	temp = *head;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->prev = NULL;
	(*head)->next = temp;
}
