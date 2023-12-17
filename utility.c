#include "shell.h"

/**
 * is_empty - chaussure
 * @str: chaussure2
 * Return: chaussure
 */


int is_empty(const char *str)
{
	while (*str != '\0')
	{
		if (!isspace((unsigned char) *str))
			return (0);
		str++;
	}
	return (1);
}
