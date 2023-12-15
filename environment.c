#include "main.h"

extern char **environ;
/**
 * Handler for environment variables
*/

void print_env(void)
{
    int i = 0;

    for (i = 0; environ[i] != NULL; i++)
    {
        printf ("%s\n", environ[i]);
    }
}
