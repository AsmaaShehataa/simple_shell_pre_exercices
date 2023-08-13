#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


void printPath()
{
        char *path = getenv("PATH");
        char *delim = ":";
        char *myTok;

        if (path == NULL)
        {
                printf("Path Not Found");

        }       
        myTok = strtok(path, delim);

	while (myTok != NULL)
	{
		printf("%s\n", myTok);
		
		myTok = strtok(NULL, delim);
	}
}

