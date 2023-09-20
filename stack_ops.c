#include "monty.h"

/**
 * free_stack - frees existing stack
 *
 * @s: pointer to top of stack pointer
 */

void free_stack(stack_t **s)
{
	stack_t *temp = NULL;

	while (*s != NULL)
	{
		temp = *s;
		*s = (*s)->next;
		free(temp);
	}
}

/**
 * push - pushes an element onto the stack
 *
 * @s: pointer to stack head
 * @n: element to add to stack
 */

void push(stack_t **s, unsigned int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = (int)n;
	node->prev = NULL;
	node->next = NULL;
	if (*s == NULL)
		*s = node;
	else
	{
		node->next = *s;
		(*s)->prev = node;
		*s = node;
	}
}

/**
 * pall - prints out the contents pf stack_t
 *
 * @s: pointer to top of stack pointer
 * @n: 0
 */

void pall(stack_t **s, unsigned int n)
{
	stack_t *looper;
	(void)n;

	if (*s == NULL)
		return;
	looper = *s;
	while (looper != NULL)
	{
		printf("%d\n", looper->n);
		looper = looper->next;
	}
}
