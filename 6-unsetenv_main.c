#include "env.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char** environ;

int main() 
{
    _unsetenv("MY_VAR"); // Delete the variable MY_VAR from the environment

    // Printing the updated environment
    for (int i = 0; environ[i] != NULL; i++) 
    {
        printf("%s\n", environ[i]);
    }

    return 0;
}
