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
	p_cerror('L');
	p_cerror('0' + line_number);
	p_serror(": ");
	p_serror(msg);
	p_cerror('\n');
}
