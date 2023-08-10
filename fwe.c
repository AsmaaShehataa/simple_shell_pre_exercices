#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int times = 5;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t parent_id;
	pid_t child_pid;
	int status;
	int i;

	i = 0;
	parent_id = getpid(); // assigning the parent id
	while( i < 5)
	{
		child_pid = fork(); //assigning a shild process id within the parent one
		if (child_pid == -1) //checking for any errors returned by fork() sys call. 
		{
			perror("Error: ");
			return (1);
		}
		else if (child_pid == 0) // checking if the process is stiill runing
		{
			printf("The child pid is: %u\n", child_pid);
			sleep(2);
			if (execve(argv[0], argv, NULL) == -1) // calling the execve whith in the child process
			{
				perror("Error: ");
			}
			//printf("The child pid is : %u\n", child_pid);
			//sleep(3); //sleeping for 3 sec
		}
		else
		{
			wait(&status); //once the child_pid != 0 (this means its done), we can execute wait.
		}
		i++;
	}
	exit(EXIT_SUCCESS);
}
