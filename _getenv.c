#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "env.h"

char *_getenv(const char *name)
{
	extern char **environ;
	int counter;
	char *token;
	char *value;
	char *env_dup;
	const char *delim = "=";
	
	//i dont need to allocate memory to token and value, because strtok returns a pointer within the given string.
	//token = malloc(sizeof(token));
	//value = malloc(sizeof(value));
	counter = 0; //initializing the counter to 0
	//token = strtok(environ[counter], delim);
	//value = NULL;
	while (environ[counter])
	{
		env_dup = strdup(environ[counter]);
		token = strtok(env_dup, delim);
		if (token && (strcmp(token, name) == 0))
		{
			value = strtok(NULL, delim);
			//not freeing the env_dup memmory the user can free it in the test file.
			//free(env_dup);
			return (value);
		}
		free(env_dup);
		counter ++;
	}
	return (NULL);
}
