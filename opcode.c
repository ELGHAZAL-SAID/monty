#include "monty.h"

/**
 * push_ - pushing an element to the stack
 *
 * @doubly: head
 * @cline: line
 * Return: none
 */
void push_(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline), dprintf(2, "usage: push integer\n");
		free_vglo(), exit(EXIT_FAILURE);
	}
	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline), dprintf(2, "usage: push integer\n");
			free_vglo(), exit(EXIT_FAILURE);
		}
	}
	n = atoi(vglo.arg);
	if (vglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * pall_ - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void pall_(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * pint_ - prints the value of top of the stack
 * @doubly: head
 * @cline: line
 * Return: none
 */
void pint_(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline), dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*doubly)->n);
}

/**
 * poping_ - delete the top element of the stack
 * @doubly: head
 * @cline: line
 * Return: none
 */
void poping_(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline), free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly, *doubly = (*doubly)->next;
	free(aux);
}

/**
 * swaping_ - swaps the top two elements
 * @doubly: head
 * @cline: line
 * Return: none
 */
void swaping_(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;
	for (; aux != NULL; aux = aux->next, m++)
		;
	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline), free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly, *doubly = (*doubly)->next;
	aux->next = (*doubly)->next, aux->prev = *doubly;
	(*doubly)->next = aux, (*doubly)->prev = NULL;
}
