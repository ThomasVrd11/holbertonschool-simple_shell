#include "shell.h"

/**
 * prompt_and_read_input - Displays prompt and read user input
 * @input_line: Double pointer to a string where the input will be stored
 */

void prompt_and_read_input(char **input_line)
{
	char *prompt = "(๑˃ᴗ˂)ﻭ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
	}
	*input_line = read_user_input();
}

/**
 * process_command - Processes the command input by the user
 * @input_line: The input line containing the command
 * @argv: Command line arguments
 * @env: The environment
 */

void process_command(char *input_line, char **argv, char **env)
{
	char **parsed_command;

	input_line[strcspn(input_line, "\n")] = 0;

	if (!is_empty(input_line))
	{
		parsed_command = parse_input(input_line);
		if (strcmp(parsed_command[0], "exit") == 0)
		{
			exit_shell();
		}
		else if (strcmp(parsed_command[0], "env") == 0)
		{
			env_variables(env);
		}
		else if (parsed_command[0])
		{
			execute_command(parsed_command, argv[0], env);
		}
		free(parsed_command);
	}
}
