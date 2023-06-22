#include "monty.h"

/**
 * queues_ - format of the data to a queue (FIFO)
 * @doubly: head
 * @cline: line
 * Return: none
 */
void queues_(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * stacks -format for the data to a stack
 * @doubly: head
 * @cline: line
 * Return: none
 */

void stacks(stack_t **doubly, unsigned int cline)
{
	(void)doubly, (void)cline;
	vglo.lifo = 1;
}

/**
 * adding - adding the top two elements
 * @doubly: head
 * @cline: line
 * Return: none
 */

void adding(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo(), exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next, aux->n += (*doubly)->n;
	poping_(doubly, cline);
}

/**
 * noping - Nothing to do
 * @doubly: head
 * @cline: line
 * Return: none
 */

void noping(stack_t **doubly, unsigned int cline)
{
	(void)doubly, (void)cline;
}

/**
 * submition - subtracts the top element to the second top element
 * @doubly: head
 * @cline: line
 * Return: none
 */

void submition(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo(), exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next, aux->n -= (*doubly)->n;
	poping_(doubly, cline);
}
