#include "monty.h"

/**
 * p_cerror - prints char to standard error
 *
 * @c: char to be printed
 */

void p_cerror(char c)
{
	write(2, &c, sizeof(char));
}

/**
 * p_serror - prints string to standard error
 *
 * @text: text to be printed
 */

void p_serror(char *text)
{
	int i;

	for (i = 0; text[i]; i++)
		p_cerror(text[i]);
}

/**
 * file_open_error - prints error msg when given file cannot be opened
 *
 * @filename: given name of file
 */

void file_open_error(char *filename)
{
	p_serror("Error: Can't open file ");
	p_serror(filename);
	p_serror("\n");
}

/**
 * no_arg_to_cmd_error - prints error msg when no argument is passed
 * to command
 *
 * @line_count: line number of command in file
 */

void no_arg_to_cmd_error(int line_count)
{
	p_serror("L");
	p_cerror('0' + line_count);
	p_serror(": usage: push integer\n");
}

/**
 * cmd_does_not_exist_error - prints error when command is not found
 *
 * @line_count: line number of command in file
 */

void cmd_does_not_exist_error(int line_count)
{
	p_serror("L");
	p_cerror('0' + line_count);
	p_serror(": unknown instruction ");
	p_serror(args[0]);
	p_serror("\n");
}
