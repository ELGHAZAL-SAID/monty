#include "monty.h"

/**
 * rotl_ - rotates the first elements
 *
 * @doubly: head
 * @cline: line
 * Return: none
 */
void rotl_(stack_t **doubly, unsigned int cline)
{
	stack_t *aux1 = NULL, *aux2 = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;
	if ((*doubly)->next == NULL)
		return;
	aux1 = (*doubly)->next, aux2 = *doubly;
	for (; aux2->next != NULL; aux2 = aux2->next)
		;
	aux1->prev = NULL, aux2->next = *doubly;
	(*doubly)->next = NULL, (*doubly)->prev = aux2;
	*doubly = aux1;
}

/**
 * rotr__ - reverse
 * @doubly: head
 * @cline: line
 * Return: none
 */
void rotr__(stack_t **doubly, unsigned int cline)
{
	stack_t *aux = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;
	if ((*doubly)->next == NULL)
		return;
	aux = *doubly;
	for (; aux->next != NULL; aux = aux->next)
		;
	aux->prev->next = NULL, aux->next = *doubly;
	aux->prev = NULL, (*doubly)->prev = aux;
	*doubly = aux;
}
