#include "main.h"

/**
 * find_command_in_path - chaussure
 * @command: chaussure
 * Return: chaussure
 */

char *find_command_in_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copie = strdup(path);
	char *saveptr;

	if (!path_copie)
	{
		perror("strdup");
		return (NULL);
	}

	char *directory;
	char *full_path = NULL;
	struct stat statbuf;

	directory = strtok_r(path_copie, ":", &saveptr);
	while (directory != NULL)
	{
		full_path = malloc(strlen(directory) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			free(path_copie);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", directory, command);
		if (stat(full_path, &statbuf) == 0 && S_ISREG(statbuf.st_mode) && (statbuf.st_mode & S_IXUSR))
		{
			break;
		}

		free(full_path);
		full_path = NULL;
		directory = strtok_r(NULL, ":", &saveptr);
	}

	free(path_copie);
	return full_path;
}
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
