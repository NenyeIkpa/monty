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
	outcome = (*s)->next->n % (*s)->n;
	pop(s, n);
	(*s)->n = outcome;
}
