#include "main.h"

/**
 * read_user_input - chaussure
 * Return: Chaussure
 */

char *read_user_input()
{
	char *input = NULL;
	size_t buffer_size = 0;
<<<<<<< HEAD
	ssize_t characters;

	characters = getline(&input, &buffer_size, stdin);
	if (characters == -1)
	{
		free(input);
		exit(EXIT_FAILURE);
	}
=======

	getline(&input, &buffer_size, stdin);
>>>>>>> 600fe33b4254ffbaf32db59c1c9ab9755f2b983e
	return (input);
}
