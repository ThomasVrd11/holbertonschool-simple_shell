#include "shell.h"

/**
 * read_user_input - chaussure
 * Return: Chaussure
 */

char *read_user_input(void)
{
	char *input = NULL;
	size_t buffer_size = 0;
	ssize_t characters;

	characters = getline(&input, &buffer_size, stdin);

	if (characters == -1)
	{
		free(input);
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("read_user_input");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
