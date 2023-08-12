#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	char *user_input = NULL; //initializing this to NULL
	size_t len = 0; // initializing this to 0
	ssize_t nred;
	extern char **environ; //using the current envirenment by calling the environ as global variable.
	int i __attribute__((unused));
	char *argv[] = {NULL, NULL};
	pid_t current_pid;
	pid_t child_pid;
	int status;
	int counter __attribute__((unused));

	//user_input = malloc(sizeof(user_input));
	/**
	 * this was removed because
	 * memory allocation is not enough, this was fixed by assigning 0 to len,
	 * and NULL to user_input(this allows getlin() to assign memory
	 * automatically).
	 * current_pid = getpid();
	 */
	while (1) //breaking the loop when the used inputs exit.
	{
		printf("$ ");
		nred = getline(&user_input, &len, stdin);
		if (nred == -1)
		{
			perror("Error:");
			free(user_input);
			return (1);
		}
		user_input[nred - 1] = '\0'; //this removes the '\n' character assigned by the getline().
		//exits the condition for the shell hwn the used types 'exit'
		if (strcmp(user_input, "exit") == 0)//this compares the userinput with "exit", and returns 0 if they matches.
		{
			free(user_input);//this frees the memory befour exit.
			break; //this beaks the while loop.
		}
		argv[0] = user_input; //setting the first element of the array to the user_input.
		//printf("retreived-line is: %s", argv[0]); //just to show case what the user inputted.
		child_pid = fork(); //creating a sub process.
		if (child_pid == -1) //checking if the sub process is failed.
		{
			perror("Error:");
			free(user_input); //very important to free the memory of user_input in each exit.
			return (-1);
		}
		else if (child_pid == 0) //this indecates that the subprocess is running
		{
			if (execve(argv[0], argv, environ) == -1) //this runs the execve and check for the error at the same time
			{
				perror("Error");
				exit(-1); //this is important for the child to exit if execve fails.
			}
		}
		else //this indicates that the sub process is still running by returning the pid != 0
		{
			wait(&status); //waits untill it's done.
		}
	}
	return (0);
}
