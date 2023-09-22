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
 * @n: line number
 */

void push(stack_t **s, unsigned int n)
{
	stack_t *node;

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
	looper = *s;
}

/**
 * pint - prints the value at the top of the stack
 *
 * @s: pointer to top of the stack pointer
 * @n: line number
 */

void pint (stack_t **s, unsigned int n)
{
	(void)n;
	if (*s == NULL)
	{
		empty_stack_error("pint", n);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*s)->n);
}

/**
 * pop - removes the value at the top of the stack
 *
 * @s: pointer to top of the stack pointer
 * @n: line number
 */

void pop(stack_t **s, unsigned int n)
{
	stack_t *temp = NULL;

	if (*s == NULL)
	{
		empty_stack_error("pop", n);
		exit(EXIT_FAILURE);
	}
	if ((*s)->next == NULL)
	{
		free(*s);
		*s = temp;

	}
	else
	{
		temp = *s;
		*s = (*s)->next;
		(*s)->prev = NULL;
		free(temp);
	}
}



