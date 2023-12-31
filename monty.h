#ifndef MONTY
#define MONTY
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global structure
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern global_t vglo;
void push_(stack_t **stack, unsigned int line_number);
void pall_(stack_t **stack, unsigned int line_number);
void pint_(stack_t **doubly, unsigned int cline);
void poping_(stack_t **doubly, unsigned int cline);
void swaping_(stack_t **doubly, unsigned int cline);
void queues_(stack_t **doubly, unsigned int cline);
void stacks(stack_t **doubly, unsigned int cline);
void adding(stack_t **doubly, unsigned int cline);
void noping(stack_t **doubly, unsigned int cline);
void submition(stack_t **doubly, unsigned int cline);
void division(stack_t **doubly, unsigned int cline);
void multiplication(stack_t **doubly, unsigned int cline);
void modulo_(stack_t **doubly, unsigned int cline);
void _putchar(stack_t **doubly, unsigned int cline);
void _pstring(stack_t **doubly, unsigned int cline);
void rotl_(stack_t **doubly, unsigned int cline);
void rotr__(stack_t **doubly, unsigned int cline);
void (*get_func(char *opc))(stack_t **stack, unsigned int line_number);
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);
void free_vglo(void);
#endif
