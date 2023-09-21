#include "monty.h"

/**
 * empty_stack_error - prints msg when pint is called
 * and stack is empty
 *
 * @op_type: type of operation to be done
 * @line_number: int
 */

void empty_stack_error(char *op_type, int line_number)
{
	char *msg;

	if (strcmp(op_type, "pint") == 0)
		msg = "can't pint, stack empty";
	else if (strcmp(op_type, "pop") == 0)
		msg = "can't pop an empty stack";
	else if (strcmp(op_type, "swap") == 0)
		msg = "can't swap, stack too short";
	else if (strcmp(op_type, "add") == 0)
		msg = "can't add, stack too short";
	else if (strcmp(op_type, "sub") == 0)
		msg = "can't sub, stack too short";
	else if (strcmp(op_type, "div") == 0)
		msg = "can't div, stack too short";
	else if (strcmp(op_type, "zero") == 0)
		msg = "division by zero";
	else if (strcmp(op_type, "mul") == 0)
		msg = "can't mul, stack too short";
	else if (strcmp(op_type, "mod") == 0)
		msg = "can't mod, stack too short";
	else if (strcmp(op_type, "pchar") == 0)
		msg = "can't pchar, stack empty";
	else if (strcmp(op_type, "out of range") == 0)
		msg = "can't pchar, value out of range";

	p_cerror('L');
	p_cerror('0' + line_number);
	p_serror(": ");
	p_serror(msg);
	p_cerror('\n');
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - prints error when malloc fails
 */

void malloc_error(void)
{
	p_serror("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
