#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc __attribute__((unused)), char **argv __attribute__ ((unused)), char **env)
{
	extern char **environ;

	printf("env address: %p\n", env);
	printf("environ address: %p\n", environ);
	exit(EXIT_SUCCESS);
}
