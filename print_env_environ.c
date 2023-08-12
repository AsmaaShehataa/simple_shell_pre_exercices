#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	extern char **environ;
	int counter;

	counter = 0;
	while (environ[counter] != NULL)
	{
		printf("%s\n", environ[counter]);
		counter++;
	}
	exit(EXIT_SUCCESS);
}
