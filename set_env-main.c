#include "env.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;

int main() {
    // Example usage of _setenv
    _setenv("MY_VAR", "new_value", 1); // Overwrite if exists
    _setenv("NEW_VAR", "value", 0);    // Add only if doesn't exist

    // Printing the updated environment
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0;
}
