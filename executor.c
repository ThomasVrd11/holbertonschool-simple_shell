#include "main.h"

/**
 * create_command_path - Creates a command path from the command input
 * @command: The command input user entered
 * Return: A pointer to the string containing the path, NULL if failed
 */
char *create_command_path(char *command)
{
	char *cmd_path;

	if (command[0] == '/')
	{
		cmd_path = strdup(command);
		if (!cmd_path)
		{
			perror("strdup");
		}
	}
	else
	{
		cmd_path = find_command_in_path(command);
	}

	return (cmd_path);
}

/**
 * execute_in_child - Executes a command in the child process
 * @cmd_path: The path command to be executed
 * @parsed_command: The parsed command with all arguments
 */
void execute_in_child(char *cmd_path, char **parsed_command)
{

	if (execve(cmd_path, parsed_command, environ) == -1)
	{
		perror("execve");
		free(cmd_path);
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_command - Forks the current process and executes a command
 * @parsed_command: The parsed command with all arguments
 */
void execute_command(char **parsed_command, char *program_name)
{
	char *cmd_path = create_command_path(parsed_command[0]);
	pid_t pid;
	int status;

	if (!cmd_path)
	{
		fprintf(stderr, "%s: %s: not found\n", program_name, parsed_command[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		execute_in_child(cmd_path, parsed_command);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(cmd_path);
	}
}
