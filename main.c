#include "monty.h"

/* Global variable declaration */
void file_error(char *av);
void error_usg(void);
int status = 0;

/**
 * main - the entry point
 * @av: list of arguments passed to our program
 * @ac: amount of args
 *
 * Return: nothing
 */

int main(int ac, char **av)
{
	FILE *file;
	size_t buf_len = 0;
	char *buf = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_num = 1;
	ssize_t line_len;

	global.data = 1;
	if (ac != 2)
		error_usg();

	file = fopen(av[1], "r");
	global.file = file;

	if (!file)
		file_error(av[1]);

	while ((line_len = getline(&buf, &buf_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buf == '\n')
		{
			line_num++;
			continue;
		}
		str = strtok(buf, " \t\n");
		if (!str || *str == '#')
		{
			line_num++;
			continue;
		}
		global.line = strtok(NULL, " \t\n");
		operation_code(&stack, str, line_num);
		line_num++;
	}
	free(buf);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * file_error - prints the error message
 * @av: the arguments vector
 *
 * Desc: To print a msg when file is not possible to open or create
 * Return: nothing
 */

void file_error(char *av)
{
	fprintf(stderr, "Error: Can't open file %s\n", av);
	exit(EXIT_FAILURE);
}

/**
 * error_usg - prints error message
 *
 * Desc: to print error only
 * if any file or more than one argument is not passed to the program
 *
 * Return: nothing
 */

void error_usg(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
