#include "monty.h"

/**
 * q_push - pushes an element onto the queue
 *
 * @s: pointer to stack head
 * @n: line number
 */

void q_push(stack_t **s, unsigned int n)
{
	stack_t *node, *looper;

	(void)n;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		malloc_error();
	node->n = atoi(args[1]);
	node->prev = NULL;
	node->next = NULL;
	if (*s == NULL)
		*s = node;
	else
	{
		looper = *s;
		while (looper->next != NULL)
			looper = looper->next;
		node->prev = looper;
		looper->next = node;
	}
}
