#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


void print_path(void)
{
        char *path;
        char *delim;
        char *myTok;

	path = getenv("PATH");
	delim = ":";
        if (path == NULL)
        {
                printf("Path Not Found");
		return (NULL);
        }       
        myTok = strtok(path, delim);
	while (myTok != NULL)
	{
		printf("%s\n", myTok);
		myTok = strtok(NULL, delim);
	}
}
