#include "monty.h"

#define SIZE 60

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
	char *args[2];
	char *filename = NULL, buffer[SIZE], *opcode = NULL, *command = NULL;
	int line_count = 0, i, element, found;
	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	stack_t *top = NULL;

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
		/* fputs(buffer, stdout); */
		command = remove_white_spaces(buffer);
		line_count++;
		/* fputs(command, stdout); */
		command[strlen(command) - 1] = '\0';
		split_command(args, command);
		opcode = args[0];
		found = 0;
		for (i = 0; operations[i].opcode; i++)
		{
			if (strcmp(opcode, operations[i].opcode) == 0)
			{
				found = 1;
				if (strcmp(opcode, "pall") == 0)
					element = 0;
				else
				{
					if (args[1] == NULL)
					{
						no_arg_to_cmd_error(line_count);
						exit(EXIT_FAILURE);
					}
					element = atoi(args[1]);
				}
				operations[i].f(&top, element);
			}
		}
		if (!found)
		{
			cmd_does_not_exist_error(line_count, opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file_ptr);
	return (0);
}