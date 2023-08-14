#include "env.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *tmp __attribute__((unused));
	int i;
	char **arr;
	char *token;

	i = 0;
	arr = get_path_arr();
	if (!arr) //checking if arr is null.
	{
		fprintf(stderr, "FAiled to get path array.\n");
		exit(EXIT_FAILURE);
	}
	token = arr[i]; //initializing the token with the first element of arr, i = 0,
	while (token != NULL)
	{
		printf("%s\n", token);
		free(arr[i]); //freeing each path string after printing.
		i++;
		token = arr[i];
	}
	free(arr); // free the array itself
	exit(EXIT_SUCCESS);
}
