#include "main.h"

/**
 * Function that execute commands, checks if executable
 */

void execute_command(char **parsed_command)
{
	pid_t pid;
	pid = fork();

	if (pid == 0)
	{
		if (execve(parsed_command[0], parsed_command, NULL) == -1)
		{
			perror("Error executing command");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Error creating a new process");
	}
}
