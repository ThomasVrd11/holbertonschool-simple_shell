#include "main.h"

/**
 * read_user_input - chaussure
 * Return: Chaussure
 */

char *read_user_input()
{
	char *input = NULL;
	size_t buffer_size = 0;
	ssize_t characters;

	characters = getline(&input, &buffer_size, stdin);
	if (characters == -1)
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	getline(&input, &buffer_size, stdin);
	return (input);
}
