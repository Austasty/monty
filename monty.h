#ifndef _MONTY_H_
#define _MONTY_H_

#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct global_var - The current opcode argument
* @line: the line string
* @line_number: number of lines to count
* @file: the file to be opened
* @data: the data structure
* @stack: stack of a linked list to work with
*
* Description: global structure created for variable identifications
*/
typedef struct global_var
{
	int line_number;
	int data;
	FILE *file;
	char *line;
	stack_t *stack;
} global_t;

global_t global;

/* Declearing the stack utility functions in doubly linked list */
stack_t *add_stack(stack_t **stack, const int n);
stack_t *queue_stack(stack_t **stack, const int n);
void free_all_stack(stack_t *stack, FILE *file);
void free_stack(stack_t *stack);
size_t print_stack_node(const stack_t *stack);

void _custom_push(stack_t **stack, unsigned int line_num);
void _custom_pall(stack_t **stack, unsigned int line_num);
void _custom_pint(stack_t **stack, unsigned int line_num);
void _custom_swap(stack_t **stack, unsigned int line_num);
void _custom_pop(stack_t **stack, unsigned int line_num);
void _custom_nop(stack_t **stack, unsigned int line_num);

void _custom_div(stack_t **stack, unsigned int div_number);
void _custom_add(stack_t **stack, unsigned int add_number);
void _custom_sub(stack_t **stack, unsigned int sub_number);
void _custom_mul(stack_t **stack, unsigned int mul_number);
void _custom_mod(stack_t **stack, unsigned int mod_number);

void check_char(stack_t **stack, unsigned int line_num);
void check_str(stack_t **stack, unsigned int line_num);
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);

void operation_code(stack_t **stack, char *str, unsigned int line_num);

int _is_digit_checks(char *string);
int _is_number_checks(char *str);

#endif /* end of_MONTY_H_ */
