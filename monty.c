#include "monty.h"

int main(int ac,char **av)
{
	(void) av;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
