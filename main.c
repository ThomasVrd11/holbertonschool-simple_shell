#include "main.h"
/**
 * main - function for shell program
 * Return: 0 if the program runs correctly, otherwise error message ()
 */
int main(void)
{
	char *input_line;
	char **parsed_command;

	while (1)
	{
		printf("(๑˃ᴗ˂)ﻭ ");
		input_line = read_user_input();
		if (!input_line)
		{
			printf("\n");
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
			env_variables();
		}
		else if (parsed_command[0])
		{
			execute_command(parsed_command);
		}
		else
		{
			printf("Error: Command not found\n");
		}
		free(parsed_command);
		free(input_line);
	}
	return (0);
}
