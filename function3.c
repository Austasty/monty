#include "monty.h"

/**
 * check_char - prints the char at the stack
 * @stack: the stack in the list
 * @line_num: number of line count
 *
 * Return: nothing
 */

void check_char(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * check_str - prints the string starting at the top of the stack,
 * @stack: stack in the list
 * @line_num: Number of lines
 *
 * Return: no return
*/

void check_str(stack_t **stack, unsigned int line_num)
{
	stack_t *cnt = *stack;

	(void)line_num;

	while (cnt)
	{
		if (cnt->n <= 0 || cnt->n > 127)
			break;
		putchar((char) cnt->n);
		cnt = cnt->next;
	}
	putchar('\n');
}

/**
* rotl - to rotate element of the stack
* @stack: pointer to stack head
* @line_num: line number count
*
* Return: nothing
*/
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *front;
	stack_t *back;

	(void) line_num;
	if (!stack || !*stack || !(*stack)->next)
		return;

	front = back = *stack;

	while (back->next)
		back = back->next;
	back->next = front;
	front->prev = back;
	*stack = front->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
* rotr - to rotate the last node in a stack
* @stack: points to the stack head in the linked list
* @line_num: line number counts
*
* Return: nothing
*/

void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *before;
	stack_t *prev;

	(void) line_num;
	if (!stack || !*stack || !(*stack)->next)
		return;

	before = *stack;

	while (before->next)
		before = before->next;

	prev = before->prev;
	before->next = *stack;
	before->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = before;
	*stack = before;
}

/**
 * _custom_nop -  does nothing to the stack
 * @stack:  stack of the linked list
 * @line_num : number of lines to count
 *
 * Return: void
 */

void _custom_nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
