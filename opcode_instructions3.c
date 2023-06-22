#include "monty.h"

/**
 * division - divides the second element the stack
 * @doubly: head
 * @cline: line
 * Return: no
 */
void division(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline), free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline), free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next, aux->n /= (*doubly)->n;
	poping_(doubly, cline);
}

/**
 * multiplication - multiplies the top element to the second of the stack
 * @doubly: head
 * @cline: line
 * Return: none
 */
void multiplication(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_vglo(), exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next, aux->n *= (*doubly)->n;
	poping_(doubly, cline);
}

/**
 * modulo_ - computes the rest of the division of second
 * @doubly: head
 * @cline: line
 * Return: none
 */
void modulo_(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_vglo(), exit(EXIT_FAILURE);
	}
	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo(), exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next, aux->n %= (*doubly)->n;
	poping_(doubly, cline);
}

/**
 * _putchar - print the char value
 *	@doubly: head
 *	@cline: line number;
 *	Return: none
 */

void _putchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_vglo(), exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
 * _pstring - print a string of stack
 * @doubly: head
 * @cline: line
 * Return: none
 */
void _pstring(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;
	while (aux && aux->n > 0 && aux->n < 128)
		printf("%c", aux->n), aux = aux->next;
	printf("\n");
}
