#include "monty.h"

/**
 * free_all_stack - frees all stacks
 * @stack: pointer to the stack
 * @file: pointer to the file
 *
 * Return: void
 */

void free_all_stack(stack_t *stack, FILE *file)
{
	free_stack(stack);
	fclose(file);
}

/**
 * free_stack - to free the stack entirely
 * @stack: pointor to the stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *visible = stack;

	while (visible != NULL)
	{
		visible = visible->next;
		free(stack);
		stack = visible;
	}
}

/**
 * queue_stack - adds to a stack in queue_node
 * @stack: points to the stack
 * @n: number of the node
 *
 * Return: newly created node, if memory allocation fails, the function will
 * return NULL.
 */

stack_t *queue_stack(stack_t **stack, const int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	stack_t *current = *stack;

	if (!newNode)
	{
		free(newNode);
		return (NULL);
	}
	newNode->n = n;

	if (!*stack)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		*stack = newNode;
		return (newNode);
	}

	while (current)
	{
		if (!current->next)
		{
			newNode->next = NULL;
			newNode->prev = current;
			current->next = newNode;
			break;
		}
		current = current->next;
	}

	return (newNode);
}

/**
 * add_stack - adds a node to the stsrt of a stack
 * @stack: pointer to the stack
 * @n: data of the new node
 *
 * Return: the reated node, if creation fails, return NULL.
 */

stack_t *add_stack(stack_t **stack, const int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newNode);
		return (NULL);
	}
	newNode->n = n;

	newNode->next = *stack;
	newNode->prev = NULL;
	if (*stack)
		(*stack)->prev = newNode;

	*stack = newNode;

	return (newNode);
}

/**
 * print_stack_node - prints the contents a stack in a linked list
 * @stack: pointer to the stack
 *
 * Return: number of elements
 */

size_t print_stack_node(const stack_t *stack)
{
	size_t index = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		index++;
	}

	return (index);
}
