#include "main.h"

/**
 * execute_command - chaussure
 * @parsed_command: chaussure
 * Return : chaussure
 */

void execute_command(char **parsed_command)
{
	char *cmd_path;
	pid_t pid;
	extern char **environ;

	if (parsed_command[0][0] == '/')
	{
		cmd_path = strdup(parsed_command[0]);
		if (!cmd_path)
		{
			perror("strdup");
			return;
		}
	}
	else
	{
		cmd_path = find_command_in_path(parsed_command[0]);
	}

	if (cmd_path == NULL)
	{
		printf("Command not found.\n");
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0) /*child process*/
	{
		if (execve(cmd_path, parsed_command, environ) == -1)
		{
			perror("execve");
			free(cmd_path);
			exit(EXIT_FAILURE); /*process end so child stop*/
		}
	}
	else /*parent process*/
	{
		int status;
		waitpid(pid, &status, 0);
		free(cmd_path);
	}
}
