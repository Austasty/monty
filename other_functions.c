#include "monty.h"

/**
 * operation_code - function used for builtins in
 * @stack: stack pointer
 * @str: string to compare with
 * @line_num: line numbers counts
 *
 * Return: nothing
 */

void operation_code(stack_t **stack, char *str, unsigned int line_num)
{
	instruction_t op[] = {
		{"push", _custom_push}, {"pall", _custom_pall},
		{"pint", _custom_pint}, {"pop", _custom_pop},
		{"swap", _custom_swap}, {"add", _custom_add},
		{"nop", _custom_nop}, {"sub", _custom_sub},
		{"div", _custom_div}, {"mul", _custom_mul},
		{"mod", _custom_mod}, {"pchar", check_char},
		{"pstr", check_str}, {"rotl", rotl},
		{"rotr", rotr}, {"#", _custom_nop},
		{"", _custom_nop}, {"\n", _custom_nop},
		{NULL, NULL}
	};
	int index = 0;

	if (!strcmp(str, "stack"))
	{
		global.data = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data = 0;
		return;
	}
	while (op[index].opcode)
	{
		if (strcmp(op[index].opcode, str) == 0)
		{
			op[index].f(stack, line_num);
			return; /* if there is a match, run the function */
		}
		index++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
	exit(EXIT_FAILURE);
}

/**
 * _is_digit_checks - checks if the string is a digit
 * @string: the string operation to check
 *
 * Return: 1 if success, 0 if not
 */

int _is_digit_checks(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}

/**
 * _is_number_checks - checks if the string is a number
 * @str: the string to check
 *
 * Return: 1 if the string is a number, else, 0.
 */

int _is_number_checks(char *str)
{
	int index;

	if (!str)
		return (0);

	for (index = 0; str[index]; index++)
		if (index < '0' || index > '9')
			return (0);

	return (1);
}
