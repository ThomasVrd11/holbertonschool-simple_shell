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
    char *cmd_path;
    pid_t pid;
	extern char **environ;

    if (parsed_command[0][0] == '/')
    {
        cmd_path = strdup(parsed_command[0]);
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
    else if (pid == 0) // Child process
    {
        if (execve(cmd_path, parsed_command, environ) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE); // Make sure to exit to prevent the child from continuing.
        }
    }
    else // Parent process
    {
        int status;
        do
        {
            waitpid(pid, &status, 0);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(cmd_path); // Free the command path only in the parent process.
}
