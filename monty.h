#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


extern char opcode_arr[][10];


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
extern stack_t *stack;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* opcodes */
void free_stack(stack_t *stack);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/* operations */
int _isdigit(char c);
int _run_op_code(char *line, unsigned int line_number);
int set_op_code_arg(char *code, unsigned int *lnumber);

/* utility funcitons */
int _isempty(stack_t *stack);
int _ascii(int n);
void print_err(unsigned int line_number);
void print_err_arg(unsigned int line_number, char *arg);
void fprint_err(const char *fmessage, unsigned int line_number);
void check_file_extension(const char *file_name);
FILE *open_file(const char *file_name);

#endif
