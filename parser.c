#include "main.h"

/**
 * Functions for parsing commands, analysis and converting
 * strtok is here to split string into tokens
 * separated by whitespaces
*/

char **parse_input(char *input_line)
{
    int buffsize = 64, position = 0;
    char **tokens = malloc(buffsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(input_line, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= buffsize)
        {
            buffsize += 64;
            tokens = realloc(tokens, buffsize *sizeof(char *));
            
            if (!tokens)
            {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return (tokens);
}