#include "main.h"

/**
 * main - function for shell program
 * Return: 0 if the programe runs correctly, otherwise error message
*/

int main()
{
    char *input_line;
    /* cc colas, prompt pour le user*/
    while (1)
    {
        printf("simple_shell> ");
        input_line = read_user_input();

        if (strcmp(input_line, "exit\n") == 0)
        {
            free(input_line);
            break;
            /*cc colas, exit si le user ecrit exit*/
        }
        /**
         * rest of code here on va attendre un peu
         * 
         * 
         * 
         * 
         * 
        */
        free(input_line);
    }
    return (0);
}