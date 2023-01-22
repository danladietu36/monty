#include "monty.h"


/**
  * _isdigit - checks if char is a digit
  * @c: character ascii
  * Return: 1 if true and 0 if false
  */
int _isdigit(char c)
{
	return ((c >= 48) && (c <= 57));
}

/**
  * print_err - helper function to print errs
  * @line_number: location of where the error occured
  */
void print_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
  * print_err_arg - helper function to print errs with argument
  * @line_number: location of where the error occured
  * @arg: argument to ber printed
  */
void print_err_arg(unsigned int line_number, char *arg)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, arg);
	exit(EXIT_FAILURE);
}

/**
  * open_file - opens the file with fopen and checks for errors
  * @file_name: name of the file
  * Return: FILE stream pointer
  */
FILE *open_file(const char *file_name)
{
	FILE *file = fopen(file_name, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (file);
}

/**
  * check_file_extension - checks the file extension for .m
  * @file_name: name of file
  */
void check_file_extension(const char *file_name)
{
	const char *ext;

	ext = file_name + (strlen(file_name) - 2);

	/* check if file_name end with .m extension */
	if (strcmp(ext, ".m") != 0)
	{
		printf("File must end with .m\n");
		exit(EXIT_FAILURE);
	}
}
