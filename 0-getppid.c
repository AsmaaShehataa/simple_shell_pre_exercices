#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * main - the entry point.
 *
 * Return: 0 when success.
 */

int main(void)
{
	pid_t ppid;
	pid_t pid;

	ppid = getppid();
	pid = getpid();
	printf("the parent process id: %u\n", ppid);
	printf("the child process id: %u\n", pid);
	exit(EXIT_SUCCESS);
}
