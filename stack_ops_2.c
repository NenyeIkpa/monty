#include "monty.h"

/**
 * swap - swaps the top two values on a stack
 *
 * @s: pointer to head pointer
 * @n: line number
 */

void swap(stack_t **s, unsigned int n)
{
	stack_t *temp;

	if (*s == NULL || (*s)->next == NULL)
		empty_stack_error("swap", n);
	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		malloc_error();

	temp->n = (*s)->next->n;
	temp->next = (*s)->next->next;
	temp->prev = (*s)->next->prev;

	(*s)->next->n = (*s)->n;
	(*s)->next->prev = *s;
	(*s)->next->next = temp->next;
	(*s)->n = temp->n;
	(*s)->prev = NULL;
	*s = temp->prev;
	free(temp);
}

/**
 * add - adds the top two elements in stack
 *
 * @s: pointer to head pointer
 * @n: line number
 */

void add(stack_t **s, unsigned int n)
{
	int outcome = 0;

	if (*s == NULL || (*s)->next == NULL)
		empty_stack_error("add", n);
	outcome = (*s)->n + (*s)->next->n;
	pop(s, n);
	(*s)->n = outcome;
}

/**
 * sub - subtracts the top element from the second on stack
 *
 * @s: pointer to top of stack pointer
 * @n: line number
 */

void sub(stack_t **s, unsigned int n)
{
	stack_t *looper;
	int outcome = 0, max = 0, next_to_max = 0;

	if (*s == NULL || (*s)->next == NULL)
		empty_stack_error("sub", n);
	looper = *s;
	max = looper->n;
	while (looper != NULL)
	{
		if (looper->n > max)
		{
			next_to_max = max;
			max = looper->n;
		}
		if (looper->n < max && looper->n > next_to_max)
			next_to_max = looper->n;
		looper = looper->next;
	}
	outcome = max - next_to_max;
	pop(s, n);
	(*s)->n = outcome;
}

/**
 * _div - dividess the second by top element in stack
 *
 * @s: pointer to head pointer
 * @n: line number
 */

void _div(stack_t **s, unsigned int n)
{
	int outcome = 0;

	if (*s == NULL || (*s)->next == NULL)
		empty_stack_error("div", n);

	if ((*s)->n == 0)
		empty_stack_error("zero", n);
	else
	{
		outcome = (*s)->next->n / (*s)->n;
		pop(s, n);
		(*s)->n = outcome;
	}
}

/**
 * mul - multiplies the second top element of the stack with
 * the top element of the stack
 *
 * @s: pointer to head pointer
 * @n: line number
 */

void mul(stack_t **s, unsigned int n)
{
	int outcome = 0;

	if (*s == NULL || (*s)->next == NULL)
		empty_stack_error("mul", n);
	outcome = (*s)->n * (*s)->next->n;
	pop(s, n);
	(*s)->n = outcome;
}
