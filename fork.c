#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	pid_t current_pid;
	pid_t child_pid;

	printf("Before fork\n");
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: ");
		return (-1);
	}
	printf("After fork\n");
	current_pid = getpid();
	printf("The id: %u\n", current_pid);
	//printf("The child process id: %u\n", child_pid);
	return (0);
	
}
