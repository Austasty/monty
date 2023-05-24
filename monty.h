#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

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

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

//i am goin to edith this function********************************************************************************
/**
 * struct global_s - global variables
 * @file: file descriptor
 * @line: line read from file
 * @line_number: line number
 * @stack: stack
 * Description: global variables
 */
typedef struct global_s
{
	FILE *file;
	char **line;
	int line_number;
	_stack_t *stack;
} global_t;


/* opcode functions */
void _push(_stack_t **stack, unsigned int line_number);
void _pall(_stack_t **stack, unsigned int line_number);
void _pint(_stack_t **stack, unsigned int line_number);
void _pop(_stack_t **stack, unsigned int line_number);
void _swap(_stack_t **stack, unsigned int line_number);
void _add(_stack_t **stack, unsigned int line_number);
void _nop(_stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);

#endif
