#include "monty.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

/**
 * isNumber - checks if a string is a number
 * @str: string to check
 * Return: true if number, false otherwise
 */
bool isNumber(const char *str)
{
    if (str == NULL || *str == '\0')
        return false;

    while (*str != '\0')
    {
        if (*str < '0' || *str > '9')
            return false;
        str++;
    }

    return true;
}

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: value to add to the stack
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *elem;
    int n = line_number;

    elem = malloc(sizeof(stack_t));
    elem->n = n;
    elem->next = *stack;
    elem->prev = NULL;

    if (*stack != NULL)
        (*stack)->prev = elem;

    *stack = elem;
}

/**
 * pall - prints all values on the stack
 * @stack: double pointer to top of stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *h;

    (void) line_number;
    h = *stack;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to top of stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack
 * @stack: double pointer to top of stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    if (temp)
        temp->prev = NULL;
    free(*stack);
    *stack = temp;
}
}
/**
 * add - adds the top two elements of the stack.
 * @stack: double pointer to the top of the stack.
 * @line_number: line number.
 *
 * This function adds the top two elements of the stack. 
 * If the stack contains less than two elements, it prints an error message and exits. 
 * After adding, it removes the top element of the stack and replaces it with the result.
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *h = *stack, *head = *stack;
    int sum = 0;
    int n = 2;
    while (head != NULL && n > 0)
    {
        sum += head->n;
        head = head->next;
        n--;
    }
    if (n == 0)
    {
        (*stack) = h->next;
        free(h);
        (*stack)->n = sum;
    }
    else
    {
        fprintf(stderr, "L%d: can't add, stack too short", line_number);
        exit(EXIT_FAILURE);
    }
}

