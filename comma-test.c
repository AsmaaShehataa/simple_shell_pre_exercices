#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char string[1024] = "this is the given string";
	const char *delims = " ";
	int i __attribute__ ((unused));
	char *token;

	token = strtok(string, delims);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delims);
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
