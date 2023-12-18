#include "shell.h"

/**
 * main - function for shell program
 * @argc: argument count
 * @argv: command line arguments
 * Return: 0 if the program runs correctly, otherwise error message ()
 */
int main(int argc, char **argv)
{
	char *input_line;
	char **parsed_command;
	char *prompt = "(๑˃ᴗ˂)ﻭ ";
	char *newline = "\n";
	(void)argc;

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		input_line = read_user_input();
		if (!input_line)
		{
			write(STDOUT_FILENO, newline, strlen(newline));
			break;
		}
		input_line[strcspn(input_line, "\n")] = 0;
		if (is_empty(input_line))
		{
			free(input_line);
			continue;
		}
		parsed_command = parse_input(input_line);
		if (strcmp(parsed_command[0], "exit") == 0)
		{
			exit_shell();
		}
		else if (strcmp(parsed_command[0], "env") == 0)
		{
			env_variables(environ);
		}
		else if (parsed_command[0])
		{
			execute_command(parsed_command, argv[0], environ);
		}
		free(parsed_command);
		free(input_line);
	}
	return (0);
}
