#ifndef _SHELL_MAIN_HEADER_
#define _SHELL_MAIN_HEADER_

/*---------LIBRARIES---------*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/*---------FUNCTIONS---------*/

char *read_user_input(void);
char **parse_input(char *input_line);
void execute_command(char **parsed_command, char *program_name);
char *find_command_in_path(char *command);
int is_empty(const char *str);
void exit_shell(void);
void env_variables(void);
extern char **environ;

/*---------THE_END----------*/

#endif
