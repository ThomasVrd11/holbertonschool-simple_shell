#include "shell.h"

/**
 * is_empty - checks if the string is empty or contain whitespace
 * @str: string to verify
 * Return: one
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
