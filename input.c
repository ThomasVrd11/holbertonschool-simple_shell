#include "main.h"

/**
 * read_user_input - chaussure
 * Return: Chaussure
 */

char *read_user_input()
{
	char *input = NULL;
	size_t buffer_size = 0;

	getline(&input, &buffer_size, stdin);
	return (input);
}
