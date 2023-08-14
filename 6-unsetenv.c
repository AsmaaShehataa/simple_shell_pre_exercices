#include "env.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char** environ;

int _unsetenv(const char *name)
{
	size_t count;
	int j;
	//find the selected variable
	for (count = 0; environ[count] != NULL; count++)
	{
		if (strncmp(environ[count], name, strlen(name)) == 0 && environ[count][strlen(name)] == '=')
		{
			//move the rest of the variables
			for (j = 0; environ[j] != NULL; j++)
			{
				environ[count] = environ[j + 1];
			}
			return 0;
		}
	}
	return -1;
}

