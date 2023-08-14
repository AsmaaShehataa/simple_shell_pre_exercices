#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


char **get_path_arr(void)
{
        char *path, *path_copy;
        char *delim;
        char *myTok;
	char **patharr;
	int counter;
	int num_dir;

	counter = 0;
	num_dir = 0;
	path = getenv("PATH");
	delim = ":";
        if (path == NULL)
        {
                printf("Path Not Found");
		return (NULL);
        }
	path_copy = strdup(path); //copyig the value of path to avoid altering values.
        myTok = strtok(path_copy, delim);
	//counting the elements to know where to add the null terminated value to the array
	while (myTok != NULL)
	{
		
		num_dir++;
		myTok = strtok(NULL, delim);
	}
	free(path_copy); //freeing the path_copy variable.
	//allocating memory based on the number of dirs in the path.
	patharr = malloc(sizeof(char *) * (num_dir + 1));
	if (!patharr)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}
	path_copy = strdup(path);
	// secon use of strtok to populate the aray.
	myTok = strtok(path_copy, delim);
	while (myTok)
	{
		patharr[counter++] = strdup(myTok);
		myTok = strtok(NULL, delim);
	}
	//setting the last element of the array to NULL.
	patharr[counter] = NULL;
	free(path_copy); //frees the last use of path_copy.
	return (patharr);
}
