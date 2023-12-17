#include "shell.h"

/**
 * exit_shell - Exits the shell
 * Description: Exits the shell when the user types the 'exit' command.
 */
void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * env_variables - Prints environment variables
 *
 * Description: Prints all the environment variables available
 * when the user types the 'env' command.
 * @env: the environment
 */
void env_variables(char **env)
{
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
