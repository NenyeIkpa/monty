#include "monty.h"

/**
 * mod - computes the of the division of the top two
 * elements in stack
 *
 * @s: pointer to head pointer
 * @n: line number
 */

void mod(stack_t **s, unsigned int n)
{
	int outcome = 0;

	if (*s == NULL || (*s)->next == NULL)
		empty_stack_error("mod", n);
	if ((*s)->n == 0)
		empty_stack_error("zero", n);
	outcome = (*s)->next->n % (*s)->n;
	pop(s, n);
	(*s)->n = outcome;
}

/**
 * pchar - prints the char at the top of the stack
 *
 * @s: pointer to top of stack pointer
 * @n: line number
 */

void pchar(stack_t **s, unsigned int n)
{
	if (*s == NULL)
		empty_stack_error("pchar", n);
	if ((*s)->n < 0 && (*s)->n > 127)
		empty_stack_error("out of range", n);
	printf("%c\n", (char)(*s)->n);
}
