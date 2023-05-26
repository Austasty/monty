#include "monty.h"

/**
 * _custom_push - adds an element to the top of the stack
 * @stack: the stack
 * @line_num: The number of line count
 *
 * Return: void
 */

void _custom_push(stack_t **stack, unsigned int line_num)
{
		char *character = global.line;

	if ((isdigit(character)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (global.data == 1)
	{
		if (!add_stack(stack, atoi(global.line)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_stack(stack, atoi(global.line)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * _custom_pall - display all the elements in the stack
 * @stack: stack head start
 * @line_num: Number of lines counts
 * Return: nothing
*/

void _custom_pall(stack_t **stack, unsigned int line_num)
{

	stack_t *newNode = *stack;

	(void)line_num;

	while (newNode != NULL)
	{
		printf("%d\n", newNode->n);
		newNode = newNode->next;
	}

}

/**
 * _custom_pint -  prints the value of the element at the top of the stack
 * @stack: stack in the list
 * @line_num: the line number count
 *
 * Return: nothing
 */

void _custom_pint(stack_t **stack, unsigned int line_num)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*stack)->n);
}

/**
* _custom_pop - removes element at the top of the stack
* @stack: the stack in linked list
* @line_num: number of lines counts
*
* Return: void
*/

void _custom_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}

/**
 * _custom_swap -   swaps positions of two elements in a stack
 * @stack: the stack of the list
 * @line_num: number of lines count
 *
 * Return: nothing
 */

void _custom_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL;
	int newNode = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	newNode = tmp->n;
	tmp->n = newNode;

	tmp->n = tmp->next->n;
	tmp->next->n = newNode;
}
