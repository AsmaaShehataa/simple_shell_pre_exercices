#include <stdio.h>
#include <stdlib.h>
#include "env.h"
int main(void)
{
	const char *name = "USER";
	char *retreived;

	//name = malloc(sizeof(name));
	//retreived = malloc(sizeof(char) * 1024);
	retreived = _getenv(name);
	printf("the retreived value of USER variable is: %s\n", retreived);
	//free(retreived);
	exit(EXIT_SUCCESS);
}
