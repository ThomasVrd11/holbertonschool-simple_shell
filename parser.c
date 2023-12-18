#include "shell.h"

/**
 * parse_input - Tokenizes an input line into an array of tokens.
 * @input_line: The input line to tokenize.
 * Description: This function takes an input line and breaks it into tokens
 * Return: A pointer to array of token. If memory allocation fails,
 * exit failure
 */

char **parse_input(char *input_line)
{
    int buffsize = 128, position = 0;
    char **tokens = malloc(buffsize * sizeof(char *));
    char *token, **tokens_temp;

    if (!tokens)
    {
        fprintf(stderr, "Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(input_line, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[position++] = token;
        if (position >= buffsize)
        {
            buffsize *= 2;
            tokens_temp = realloc(tokens, buffsize * sizeof(char *));
            if (!tokens_temp)
            {
                free(tokens);
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
            tokens = tokens_temp;
        }
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}
