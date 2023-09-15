Simple_Shell Project README

Authors/Contributors
*King-David Akuoko*
*Ama Appiah-Danquah*

SPECIFICATION OF THE SIMPLE SHELL PROJECT

*Some functions and systems calls used for the shell task*
(stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork), etc.

COMPILATION

The Simple shell will be compiled this way:
*gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh*

TESTING

Your shell should work like this in interactive mode:
*$ ./hsh ($) /bin/ls hsh main.c shell.c ($) ($) exit*

SOME TASKS UNDERTAKEN FOR THE SIMPLE SHELL 

The Simple shell created is able to:

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- Handle command lines with arguments.
- Implement the exit built-in, that exits the shell.
- Implement the builtin command cd.
- Handle the && and || shell logical operators.
- etc.
