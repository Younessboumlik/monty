#include "monty.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
bool isNumber(const char *str) {
	    if (str == NULL || *str == '\0') {
		            return false;
			        }

	        while (*str != '\0') {
			        if (*str < '0' || *str > '9') {
					            return false;
						            }
				        str++;
					    }

		    return true;
}
void push(stack_t **stack, unsigned int line_number){
	stack_t *elem;
	int n = line_number;
	elem = malloc(sizeof(stack_t));
	
	elem->n = n;
	elem->next = *stack;
	elem->prev = NULL;
	if (*stack != NULL){
		(*stack)->prev = elem;
	}
	*stack = elem;
	
}
void pall(stack_t **stack,unsigned int line_number)
{
	     stack_t *h ;
	(void) line_number;
	
	h = *stack;
	while(h != NULL){
		printf("%d\n",h->n);
		
		h = h->next;
	}
	
}
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}
