#include "monty.h"
/**
 *add - adds the top two stack elementa
 *@head: pointer to head pointer
 *@ln: line no
 */
void add(stack_t **head, unsigned int ln)
{
	stack_t *node, *temp = *head;

	(void)ln;
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	node->n = temp->n + temp->next->n;
	node->next = temp->next->next;
	node->prev = NULL;
	*head = temp->next;
	free(temp);
	free(*head);
	*head = node;
}
