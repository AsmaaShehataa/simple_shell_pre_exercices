#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * comma_func - a function that used strtok(),
 * @str: the given string.
 * @delims: the specified delims.
 *
 * Return: the generated array of tokens.
 */

char **comma_func(char *str, const char *delims)
{
	char *token;
	char **returned_tkn;
	int i;

	token = strtok(str, delims);
	i = 0;
	while (token != NULL)
	{
		returned_tkn[i] = token;
		token = strtok(NULL, delims);
		i++;
	}
	return (returned_tkn);
}
