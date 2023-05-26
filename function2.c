#include "monty.h"

/**
 * _custom_add - adds the first two data of the stack.
 * @stack: stack head
 * @add_number: line_number
 * Return: no return
*/
void _custom_add(stack_t **stack, unsigned int add_number)
{
	int total;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", add_number);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	total = ((*stack)->next->n) + ((*stack)->n);
	_custom_pop(stack, add_number);
	(*stack)->n = total;
}

/**
 * _custom_div - divides  element of a stack
 * @stack: main stack
 * @div_number: number of lines to count
 *
 * Return: nothing
 */

void _custom_div(stack_t **stack, unsigned int div_number)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", div_number);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", div_number);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);

		return;
	}

	res = ((*stack)->next->n) / ((*stack)->n);
	_custom_pop(stack, div_number);
	(*stack)->n = res;
}

/**
 * _custom_sub -  substracts the first two top elements of the stack
 * @stack: main stack
 * @sub_number: number of lines
 *
 * Return: void
 */

void _custom_sub(stack_t **stack, unsigned int sub_number)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", sub_number);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	res = ((*stack)->next->n) - ((*stack)->n);
	_custom_pop(stack, sub_number);
	(*stack)->n = res;
}

/**
 * _custom_mul - multiplies values if it exist
 * in the stack of the list
 * @stack: stack in the linked list
 * @mul_number: line number
 *
 * Return: void
 */

void _custom_mul(stack_t **stack, unsigned int mul_number)
{
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", mul_number);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	res = (*stack)->n * (*stack)->next->n;
	_custom_pop(stack, mul_number);
	(*stack)->n = res;
}

/**
 * _custom_mod - calculates the remainder of data after a division
 * @stack: main stack of the linked list
 * @mod_number: number of lines to count
 *
 * Return: void
 */

void _custom_mod(stack_t **stack, unsigned int mod_number)
{
	int res;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", mod_number);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", mod_number);
		free_all_stack(*stack, global.file);
		exit(EXIT_FAILURE);
		return;
	}

	res = ((*stack)->next->n) % ((*stack)->n);
	_custom_pop(stack, mod_number);
	(*stack)->n = res;
}
