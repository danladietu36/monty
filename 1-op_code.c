#include "monty.h"
#include "external.h"


/**
  * set_op_code_arg - sets the operation code argument
  * @code: code to check if valid
  * @lnumber: argument at that line
  * Return: -1 if failed and 0 success
  */
int set_op_code_arg(char *code, unsigned int *lnumber)
{
	int length, i;

	if (code == NULL)
		return (-1);

	length = strlen(code);

	for (i = 0; i < length; i++)
	{
		if (_isdigit(code[i]))
		{
			*lnumber = atoi(code);
			return (0);
		}
	}
	return (-1);
}

/**
  * _run_op_code - excutes the opcode line
  * @line: line gotten from monty file
  * @line_number: line index in monty file
  * Return: 1 if success and -1 if fialed
  */
int _run_op_code(char *line, unsigned int line_number)
{
	char *token;

	unsigned int lnumber, i;

	token = strtok(line, " ");
	if (token == NULL)
		return (-1);
	if (strcmp(token, OPCODES[0].opcode) == 0)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
		{
			if (set_op_code_arg(token, &lnumber) < 0)
				print_err(line_number);
		}
		else
			print_err(line_number);
		OPCODES[0].f(&stack, lnumber);
		return (1);
	}
	else if (strcmp(token, "pall") == 0)
	{
		pall(&stack);
		return (1);
	}
	for (i = 1; i < OPCODE_MAX_LEN; i++)
	{
		if (strcmp(token, OPCODES[i].opcode) == 0)
		{
			if (OPCODES[i].f != NULL)
				OPCODES[i].f(&stack, line_number);
			return (1);
		}
	}
	if (token != NULL)
		print_err_arg(line_number, token);
	return (-1);
}
