#include "monty.h"
/**
 *push - pushes an item onto the stacked list
 *@head: pointrr to list head pointer
 *@ln: line number
 */
void push(stack_t **head, unsigned int ln)
{
	stack_t *node = malloc(sizeof(stack_t));

	(void)ln;
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	node->n = item;
	node->prev = NULL;
	node->next = *head;
	if (*head)
		(*head)->prev = node;
	*head = node;
}
