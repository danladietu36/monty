#include "monty.h"
/**
 *codexec - runs opcode
 *@opcode: opcode
 *@stack: poinyer to head of list pointer
 *@ln: line number
 */
void codexec(char *opcode, stack_t **stack, unsigned int ln)
{
	instruction_t arr[] = {{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap}, {"add", add}, {NULL, NULL}};
	int i = 0;

	while (i < 6)
	{
		if (strcmp(opcode, arr[i].opcode) == 0)
			arr[i].f(stack, ln);
		i++;
	}
}
