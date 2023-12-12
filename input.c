#include "main.h"

/**
 * Functions for input handling
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
	return (input);
}
