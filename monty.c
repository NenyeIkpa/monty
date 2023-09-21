#include "monty.h"

#define SIZE 1024

/**
 * main - entry point to interpreter for monty bytecode files
 *
 * @argc: total number of arguments passed to main
 * @argv: list of arguments passed to main
 *
 * Return: int
 */

int main(int argc, char **argv)
{
	FILE *file_ptr;
	char *args[2] = {NULL, NULL};
	char *filename = NULL, buffer[SIZE], *command = NULL;
	stack_t *top = NULL;
	int line_number = 0;

	if (argc < 2)
	{
		p_serror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file_ptr = fopen(filename, "r");
	if (file_ptr == NULL)
	{
		file_open_error(filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, SIZE, file_ptr) != NULL)
	{
		command = remove_white_spaces(buffer);
		command[strlen(command) - 1] = '\0';
		split_command(args, command);
		line_number++;
		if (args[0] == NULL || strcmp(args[0], "nop") == 0)
			continue;
		else
			run_command(&file_ptr, &top, args, line_number);
	}

	fclose(file_ptr);
	free_stack(&top);
	return (0);
}

/**
 * run_command - processes and runs commands
 *
 * @fp: pointer to file
 * @top: pointer to top of stack
 * @args: commands to be run
 * @line_number: line number of command
 */

void run_command(FILE **fp, stack_t **top, char *args[2], int line_number)
{
	char *opcode = args[0];
	int i, found = 0, element;
	instruction_t operations[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {NULL, NULL}
	};

	for (i = 0; operations[i].opcode; i++)
	{

		if (strcmp(opcode, operations[i].opcode) == 0)
		{
			found = 1;
			if (strcmp(opcode, operations[0].opcode) == 0)
			{
				if (args[1] == NULL || !is_a_number(args[1]))
				{
					no_arg_to_cmd_error(line_number);
					fclose(*fp);
					free_stack(top);
					exit(EXIT_FAILURE);
				}
				  element = atoi(args[1]);
			}
			else
				element = line_number;
		operations[i].f(top, element);
		}
	}
	if (!found)
	{
		cmd_does_not_exist_error(line_number, opcode);
		free_stack(top);
		fclose(*fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_a_number - checks if arg passed is an int
 *
 * @arg: arg passed
 *
 * Return: 1 when true else 0
 */

int is_a_number(char *arg)
{
	if (atoi(arg) == 0 && strcmp(arg, "0") != 0)
		return (0);
	else
		return (1);
}

/**
 * split_command - splits given command into strings
 *
 * @command: given command
 * @args: pointer to array of strings;
 */

void split_command(char *args[2], char *command)
{
	char *token = NULL;
	int space_count = 0;

	token = strtok(command, " ");
	args[0] = token;
	space_count++;
	while (token != NULL)
	{
		if (space_count == 2)
			break;
		token = strtok(NULL, " ");
		args[1] = token;
		space_count++;
	}
}
/**
 * remove_white_spaces - removes white spaces in a string
 *
 * @str: provided string
 *
 * Return: string
 */

char *remove_white_spaces(char *str)
{
	int i, j = 0;

	for (i = 0; (size_t)i < strlen(str); i++)
	{
		if (str[i] != ' ' || (i > 0  && str[i - 1] != ' '))
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}
