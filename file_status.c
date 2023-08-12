#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        int counter;
        struct stat status;

        if(argc < 2)
        {
                printf("Usage: %s supply the arguments.\n", argv[0]);
                return (1);
        }
        counter = 1;
        while (argv[counter])
        {
                printf("%s:", argv[counter]);
                if (stat(argv[counter], &status) == 0)
                {
                        printf("File found\n");
                }
                else
                {

                 
		 	printf("File not  found\n");

                }
		counter++;
        }       
        return (0);
}

