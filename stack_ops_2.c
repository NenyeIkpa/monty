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
	{
		empty_stack_error("swap", n);
		exit(EXIT_FAILURE);
	}
	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}

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
