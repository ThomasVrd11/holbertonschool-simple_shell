#include "shell.h"

/**
 * check_command_path - Checks if a command exists in a directory
 * @dir: Directory to check command
 * @command: Command
 * Return: Full path to command if found, NULL if not
 */
char *check_command_path(const char *dir, const char *command)
{
	char *full_path;
	struct stat statbuf;
	size_t length = strlen(dir) + strlen(command) + 2;

	full_path = malloc(length);
	if (!full_path)
	{
		perror("malloc");
		return (NULL);
	}

	sprintf(full_path, "%s/%s", dir, command);
	if (stat(full_path, &statbuf) == 0 &&
		S_ISREG(statbuf.st_mode) && (statbuf.st_mode & S_IXUSR))
	{
		return (full_path);
	}

	free(full_path);
	return (NULL);
}

/**
 * find_command_in_path - Searches for the command in PATH
 * @command: Command to find
 * Return: Path to command if found, NULL if not
 */

char *find_command_in_path(char *command)
{
	char *path, *path_copy, *token, *saveptr, *cmd_path = NULL;
	size_t path_len;

	path = getenv("PATH");
	if (!path)
	{
		return (NULL);
	}

	path_len = strlen(path) + 1;
	path_copy = malloc(path_len);
	if (!path_copy)
	{
		perror("malloc");
		return (NULL);
	}
	strncpy(path_copy, path, path_len);

	for (token = strtok_r(path_copy, ":", &saveptr); token != NULL;
	token = strtok_r(NULL, ":", &saveptr))
	{
		cmd_path = check_command_path(token, command);
		if (cmd_path)
		{
			break;
		}
	}

	free(path_copy);
	return (cmd_path);
}
