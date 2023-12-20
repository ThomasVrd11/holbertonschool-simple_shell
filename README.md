<div align="center">
    <h1>Simple Shell </h1>
    <h6>
    <a href="#introduction">Intro</a>
    ·
    <a href="#usage">Usage</a>
    ·
    <a href="#howto">Use it</a>
    ·
    <a href="#authors">Authors</a>
  </h6>
</div>

<h2 id="introduction">Introduction</h2>

We're thrilled to present our project from Holberton School, where we've tackled the challenge of creating our own simple shell in C. This project highlights our growing expertise in systems programming by strictly utilizing a limited set of standard library functions.
Big shoutout to Colas and Thomas from HolbertonSchool #C22 for bringing this project to life !

## List of allowed functions and system calls

* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)

## Project requirements
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

## What have we done exactly ?

- Write a README
- Write a man for your shell.
- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. 
- Write a beautiful code that passes the Betty checks
- Write a UNIX command line interpreter.
- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)
- Handle command lines with arguments
- Handle the PATH
- fork must not be called if the command doesn’t exist
- Implement the exit built-in, that exits the shell
Usage: exit
- You don’t have to handle any argument to the built-in exit
- Implement the env built-in, that prints the current environment

# Flowchart
<img width="583" alt="Image PNG" src="https://github.com/ThomasVrd11/holbertonschool-simple_shell/assets/146711276/1c9ac420-a2cf-41fe-8832-cceaf75576ca">


## Important functions quick description

- read_user_input: Reads input from the user and returns it as a string.
- parse_input: Splits the input string into a command and arguments array.
- find_command_in_path: Searches the system path to locate the executable for a command.
- is_empty: Checks if a given string is empty or contains only whitespace.
- exit_shell: Exits the shell program cleanly.
- env_variables: Prints the current environment variables.
- execute_command: Runs the specified command with the provided arguments and environment.
- create_command_path: Concatenates a directory path and a command to form a full command path.
- prompt_and_read_input: Displays a prompt and reads the user's input.
- process_command: Handles the processing and execution flow of the user's command.
check_command_path: Verifies if a command exists in the specified directory.
<h2 id="usage">Getting started</h2>

To use this program:

Clone the repo,

    git clone https://github.com/ThomasVrd11/holbertonschool-simple_shell.git

Compile it with,

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o my_shell

Have fun !

    ./my_shell

<h2 id="howto">How to use it</h2>

In order to use this shell, in a terminal, first run the program:
`./my_shell`

It will then display a simple prompt and wait for commands.

`(๑˃ᴗ˂)ﻭ`

Exemple 1 :
```c
(๑˃ᴗ˂)ﻭ pwd
/root/holbertonschool-simple_shell
```
Exemple 2 :
```c
(๑˃ᴗ˂)ﻭ ls -a
.  ..  .git  AUTHORS  README.md  built.c  executor.c  find_command.c  input.c  input_process.c  main.c  man_1_simple_shell.1  my_shell  parser.c  shell.h  utility.c
(๑˃ᴗ˂)ﻭ
```
Exemple 3 (non interactive) :
````c
╰─ echo "/bin/ls" | ./my_shell                                                                                                                                            ─╯
AUTHORS                 built.c                 find_command.c          input.c                 main.c                  my_shell                shell.h
README.md               executor.c              hsh                     input_process.c         man_1_simple_shell.1    parser.c                utility.c
``````

### List of built-ins
* exit  
    Exits the shell
* pwd  
    Print the full path of the current/working directory
* env   
    Print the list of environment variables
<h2 id="authors">Authors</h2>

- [Thomas VIARD](https://github.com/ThomasVrd11)
- [François COLAS](https://github.com/fgmcolas)

> Project developed during the [Holberton School](https://www.holbertonschool.com/) program.
