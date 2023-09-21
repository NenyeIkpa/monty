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
		msg = "can'can't add, stack too short";
	p_cerror('L');
	p_cerror('0' + line_number);
	p_serror(": ");
	p_serror(msg);
	p_cerror('\n');
}

/**
 * malloc_error - prints error when malloc fails
 */

void malloc_error(void)
{
	p_serror("Error: malloc failed\n");
}
