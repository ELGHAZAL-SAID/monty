#include "monty.h"

/**
 * get_func - selects the correct function
 * @opc: opcode
 * Return: pointer to the function
 */
void (*get_func(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push_},
		{"pall", pall_},
		{"pint", pint_},
		{"pop", poping_},
		{"swap", swaping_},
		{"queue", queues_},
		{"stack", stacks},
		{"add", adding},
		{"nop", noping},
		{"sub", submition},
		{"mul", multiplication},
		{"div", division},
		{"mod", modulo_},
		{"pchar", _putchar},
		{"pstr", _pstring},
		{"rotl", rotl_},
		{"rotr", rotr__},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
		if (_strcmp(instruct[i].opcode, opc) == 0)
			break;
	return (instruct[i].f);
}
