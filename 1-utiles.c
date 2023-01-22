#include "monty.h"

/**
  * fprint_err - prints formated error message
  * @fmessage: formated message
  * @line_number: line index of file
  */
void fprint_err(const char *fmessage, unsigned int line_number)
{
	fprintf(stderr, fmessage, line_number);
	exit(EXIT_FAILURE);
}

/**
  * _isempty - checks if stack is empty
  * @stack: top of stack
  * Return: 1 if success and 0 if failed
  */
int _isempty(stack_t *stack)
{
	return (stack == NULL);
}

/**
  * _ascii - checks if number in ascii range
  * @n: number to check
  * Return: 1 on success 0 on fail
  */
int _ascii(int n)
{
	return ((n >= 0) && (n <= 127));
}
