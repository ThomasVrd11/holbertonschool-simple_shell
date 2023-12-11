#include "main.h"

/**
 * Functions for input handling
 */

char *read_user_input()
{
	char *input = NULL;
	size_t buffer_size = 0;
	getline(&input, &buffer_size, stdin);
	return input;
}
