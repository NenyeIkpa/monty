#include "monty.h"

/**
 * empty_stack_error - prints msg when pint is called
 * and stack is empty
 *
 * @line_number: int
 */

void empty_stack_error(int line_number)
{
	p_cerror('L');
	p_cerror('0' + line_number);
	p_serror(": can't pint, stack empty\n");
}
