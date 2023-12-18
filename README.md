<div align="center">
    <h1>Simple Shell <img src="https://w7.pngwing.com/pngs/77/473/png-transparent-computer-icons-computer-terminal-others-angle-rectangle-logo.png" width=60 align=center> </h1>
    <h6>
    <a href="https://github.com/ThomasVrd11/holbertonschool-simple_shell#introduction-">Intro</a>
    ·
    <a href="https://github.com/ThomasVrd11/holbertonschool-simple_shell#list-of-allowed-functions-and-system-calls-">Allowed Functions</a>
    ·
    <a href="https://github.com/ThomasVrd11/holbertonschool-simple_shell#usage-">Usage</a>
    ·
    <a href="https://github.com/ThomasVrd11/holbertonschool-simple_shell#how-to-use-it-">Use it</a>
    ·
    <a href="https://github.com/ThomasVrd11/holbertonschool-simple_shell#authors-">Authors</a>
  </h6>
</div>

## Introduction

This is a Holberton School project that consists of making our own simple shell with a limited amount of functions from the standard library.

### List of allowed functions and system calls
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

## Usage

To use this program:

Clone the repo

    git clone https://github.com/ThomasVrd11/holbertonschool-simple_shell.git

Compile it with

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o my_shell

### How to use it

In order to use this shell, in a terminal, first run the program:

`./my_shell`

It will then display a simple prompt and wait for commands.

`(๑˃ᴗ˂)ﻭ`

Exemple 1 :
```
(๑˃ᴗ˂)ﻭ pwd
/root/holbertonschool-simple_shell
```
Exemple 2 :
```
(๑˃ᴗ˂)ﻭ ls -a
.  ..  .git  AUTHORS  README.md  built.c  executor.c  find_command.c  input.c  input_process.c  main.c  man_1_simple_shell.1  my_shell  parser.c  shell.h  utility.c
(๑˃ᴗ˂)ﻭ
```
### List of built-ins
* exit  
    Exits the shell
* pwd  
    Print the full path of the current/working directory
## Authors

- [Thomas VIARD](https://github.com/ThomasVrd11)
- [François COLAS](https://github.com/fgmcolas)

> Project developed during the [Holberton School](https://www.holbertonschool.com/) program.
