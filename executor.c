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

	if (!path_copie)
	{
		perror("strdup");
		return (NULL);
	}

	char *directory;
	char *full_path;
	struct stat statbuf;

	directory = strtok(path_copie, ":");
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
		if (stat(full_path, &statbuf) == 0 && statbuf.st_mode & S_IXUSR)
		{
			free(path_copie);
			return (full_path);
		}

		free(full_path);
		directory = strtok(NULL, ":");
	}
	free(path_copie);
	return (NULL);
}

/**
 * execute_command - chaussure
 * @parsed_command: chaussure
 * Return : chaussure
 */

void execute_command(char **parsed_command)
{
	char *cmd_path = find_command_in_path(parsed_command[0]);
	pid_t pid;

	if (cmd_path == NULL)
	{
		printf("Command not found: %s\n", parsed_command[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		/* dans le chhild process */
		if (execve(cmd_path, parsed_command, NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		/* dans le process papounet */
		wait(NULL);
		free(cmd_path);
	}
	else
	{
		/* si fork foire */
		perror("Error creating a new process");
	}
}
