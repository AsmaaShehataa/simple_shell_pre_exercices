#include <stdlib.h>
#include <stdio.h>
/**
 * main - the entry point.
 * @argv: the argument vector.
 *
 * Return: success.
 */

int main(int ac __attribute__((unused)), char *av[])
{
	int i;
	char *buffer;
	
	i = 1;
	while (av[i])
	{
		buffer = av[i];
		printf("%s\n", buffer);
		i++;
	}
	exit(EXIT_SUCCESS);
}
