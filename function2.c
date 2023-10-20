#include "monty"
/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number
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
    }
}

/**
 * nop - does nothing
 * @stack: double pointer to the stack to be manipulated
 * @line_number: number of lines in case of an error
 *
 * Description: opcode that doesn’t do anything
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
