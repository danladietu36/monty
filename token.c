#include "monty.h"
/**
 *token - splits string into tokens
 *@line: string to be split
 *@errno: sets error codes
 *Return: pointer to first token
 */
char *token(char *line, int *errno)
{
	char *codes[] = {"push", "pall", "swap", "add", "nop", "pop", NULL};
	char *op = NULL, *arg = NULL, *tok;
	int i = 0;

	tok = strtok(line, " $\n");
	if (tok)
		op = strdup(tok);
	while (codes[i])
	{
		if (strcmp(op, codes[i]) == 0)
		{
			if (i == 0)
			{
				arg = strtok(NULL, " \n");
				if (arg)
					item = atoi(arg);
			}
			break;
		}
		i++;
	}
	if (!codes[i])
		*errno = 1;
	else if (i == 0 && (arg == NULL || !item))
		*errno = 2;
	return (op);
}
