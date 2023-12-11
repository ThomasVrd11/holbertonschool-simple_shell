#include "main.h"

/**
 * main - function for shell program
 * Return: 0 if the programe runs correctly, otherwise error message
 */

int main()
{
	char *input_line;
	char **parsed_command;
	/* cc colas, prompt pour le user*/
	while (1)
	{
		printf("simple_shell> ");
		input_line = read_user_input();

		if (!input_line)
		{
			printf("\n");
			break;
		}

		if (strcmp(input_line, "exit\n") == 0)
		{
			free(input_line);
			break;
			/*cc colas, exit si le user ecrit exit*/
		}
		parsed_command = parse_input(input_line);

		if (parsed_command[0])
		{
			if (is_command_executable(parsed_command[0]))
			{
				execute_command(parsed_command);
			}
		}
		else
		{
			printf("Error: Command not found");
		}
		/**
		 * ona  besoin de logique pour 
		 * execute la commande parsed
		 * avec des builtins 
		 *
		 *
		 *
		 */
		free(parsed_command);
		free(input_line);
	}
	return (0);
}