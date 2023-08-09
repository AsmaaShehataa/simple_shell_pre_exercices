#include <stdio.h>
#include <stdlib.h> 

/**
 * main function - entry point
 * Return: 0 on success
 *
*/

int main()
{
	char *myarr = NULL;
	size_t len = 0;
	ssize_t myfile;

	printf("$ ");

	
	myfile = getline(&myarr, &len, stdin);
	if ( myfile == -1)
	{
		printf("Error while reading the input\n");
		return (-1);

	}

	printf("%s", myarr);
		free(myarr);
		
	return 0;

}
