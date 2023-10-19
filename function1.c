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
#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	int stack_length = 0, temp;

	current_node = *stack;
	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current_node = *stack;
	temp = current_node->n;
	current_node->n = current_node->next->n;
	current_node->next->n = temp;
}
