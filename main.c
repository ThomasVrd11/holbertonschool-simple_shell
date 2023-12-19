#include "shell.h"

/**
 * main - entry point for our simple shell program, checks for interactive
 *  or non-interactive
 * @argc: count of command line arguments
 * @argv: command line arguments array
 * Return: 0 if successful exit
*/

int main(int argc, char **argv)
{
	char *input_line;
	char *newline = "\n";
	(void)argc;

	while (1)
	{
		prompt_and_read_input(&input_line);
		if (!input_line)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, newline, strlen(newline));
			}
			break;
		}
		process_command(input_line, argv, environ);
		free(input_line);
	}

	return (0);
}
