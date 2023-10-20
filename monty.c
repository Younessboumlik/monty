#define _GNU_SOURCE
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "monty.h"
#include <string.h>
#include <stdbool.h>

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

/**
 * main - entry point for monty bytecode interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
    FILE *f;
    char *token;
    unsigned int n;
    int nbr_line = 1;
    char *line = NULL;
    int i;
    size_t a = 0;
    stack_t *stack = NULL;
    instruction_t instr[] = {{"push", &push}, {"pall", &pall}, {"nop", &nop}, {"pint", &pint}, {"pop", &pop}, {"add", &add};

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    else
    {
        while (getline(&line, &a, f) != -1)
        {
            if (line[strlen(line) - 1] == '\n')
            {
                line[strlen(line) - 1] = '\0';
            }
            token = strtok(line, " ");
            while (token != NULL)
            {
                for (i = 0; i < 6; i++)
                {
                    if (strcmp(token, instr[i].opcode) == 0)
                    {
                        break;
                    }
                }
                if (i == 3)
                {
                    fprintf(stderr, "L%d: unknown instruction %s\n", nbr_line, token);
                    exit(EXIT_FAILURE);
                }
                token = strtok(NULL, " ");
                if (token != NULL)
                {
                    if (isNumber(token) == false && strcmp(instr[i].opcode, "push") == 0)
                    {
                        fprintf(stderr, "L%d: usage: push integer\n", nbr_line);
                        exit(EXIT_FAILURE);
                    }
                    n = atoi(token);
                    break;
                }
                else
                {
                    if (strcmp(instr[i].opcode, "push") == 0)
                    {
                        fprintf(stderr, "L%d: usage: push integer\n", nbr_line);
                        exit(EXIT_FAILURE);
                    }
                    n = nbr_line;
                }

            }
            (instr[i].f)(&stack, n);
            nbr_line++;
        }
    }
    fclose(f);
    free(line);
    return (0);
}
