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
		if (*str != ' ' && *str != '\t' && *str != '\n' &&
			*str != '\r' && *str != '\f' && *str != '\v')
			return (0);
		str++;
	}
	return (1);
}
