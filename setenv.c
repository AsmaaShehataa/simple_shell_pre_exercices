#include "env.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	char *new__envrion_var;
	int i, j, env_count;
	 char **new_environ_var_env;

	for (i = 0; environ[i]; i++)
	{ //checks if the variable already exist as per man 3 setenv
		if(strncmp(environ[i], name, strlen(name)) == 0)
		{
			if (overwrite)
			{
				snprintf(environ[i], strlen(name) + strlen(value) + 2, "%s = %s", name, value);
				return 0;
			} else
			{
				return 0; //variable exist but not overwritten
			}
			//case 2 if the variable doesn't exist, we will create new one by malloc
			new__envrion_var = (char *)malloc(sizeof(char *) * (j + 2));
			if (new__envrion_var == NULL)
			{
				perror("malloc");
				return -1;
			}
			snprintf(new__envrion_var, strlen(name) + strlen(value) + 2, "%s = %s", name, value);

			for (env_count = 0; environ[env_count] != NULL; env_count++) {}

			//allocate new memory fro the new environ array variable in line 24
			new_environ_var_env = (char **)malloc(sizeof(char *) * (env_count + 2));
			if (!new_environ_var_env)
			{
				perror ("malloc");
				free(new_environ_var_env);
				return -1;
			}
			//copy all elements from old environment to new environment and add our new element at the end of it
			for (i = 0; i < env_count; i++)
			{
				new_environ_var_env[i] = environ[i];
			}
			// add the new variable entry
			new_environ_var_env[env_count] = new__envrion_var;
			new_environ_var_env[env_count + 1] = NULL;
			// replacing the old envrion with the new one
			environ = new_environ_var_env;
		}
	}
	return 0;
}

