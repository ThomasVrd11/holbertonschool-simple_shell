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
	char *directory;
	char *full_path = NULL;
	struct stat statbuf;

	if (!path_copie)
	{
		perror("strdup");
		return (NULL);
	}

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
