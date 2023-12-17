#include "shell.h"
/**
 * find_command_in_path - chaussure
 * @command: chaussure
 * Return: chaussure
 */

char *find_command_in_path(char *command)
{
	char *path = getenv("PATH");
	size_t path_len = strlen(path);
	char *path_copie = malloc(path_len + 1);
	char *saveptr;
	char *directory;
	char *f_path = NULL;
	struct stat statbuf;

	if (!path_copie)
	{
		perror("malloc");
		return (NULL);
	}
	memcpy(path_copie, path, path_len + 1);
	directory = strtok_r(path_copie, ":", &saveptr);
	while (directory != NULL)
	{
		f_path = malloc(strlen(directory) + strlen(command) + 2);
		if (f_path == NULL)
		{
			perror("malloc");
			free(path_copie);
			return (NULL);
		}
		sprintf(f_path, "%s/%s", directory, command);
		if (stat(f_path, &statbuf) == 0 && S_ISREG(statbuf.st_mode) &&
		(statbuf.st_mode & S_IXUSR))
		{
			break;
		}
		free(f_path);
		f_path = NULL;
		directory = strtok_r(NULL, ":", &saveptr);
	}
	free(path_copie);
	return (f_path);
}
