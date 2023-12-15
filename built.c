#include "main.h"
extern char **environ;

/**
 * 
 * exit_shell - Exits shell when typing exit
*/

void exit_shell(void)
{
    exit(EXIT_SUCCESS);
}

/**
 * env_variables - prints environment variables when typing env
*/

void env_variables(void)
{
    int i = 0;

    for (i = 0; environ[i] != NULL; i++)
    {
        printf ("%s\n", environ[i]);
    }
}
