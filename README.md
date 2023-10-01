# Wimix: A Simple Linux Shell

## Description
Wimix is a simple Linux shell that can handle internal and external commands. Internal commands are those which are interpreted by the shell program itself, without requiring a different program to handle the expected operations. Examples of internal commands are cd, echo, and pwd. External commands are those which are not handled directly by the shell program but by an external program. Examples of external commands are ls, cat, date, rm, and mkdir. Wimix can also execute external commands in a thread-based manner using the &t suffix.

## Prerequisites
To run Wimix, you need to have a Linux system with the following libraries and tools installed:

- GCC compiler
- Make utility
- POSIX threads library

## Installation
To install Wimix, follow these steps:

1. Clone this repository or download the source code as a zip file.
2. Navigate to the directory where the source code is located.
3. Run `make` to compile the source code and generate the executable file `wimix`.
4. Optionally, you can run `make install` to copy the executable file to `/usr/local/bin` for easier access.

## Usage
To use Wimix, follow these steps:

1. Run `./wimix` or `wimix` (if you installed it) to launch the shell.
2. You will see a prompt that shows your current working directory and username, followed by `$`.
3. Type any of the supported commands and press Enter to execute them.
4. To exit the shell, type `exit` or press Ctrl+D.

## Supported Commands
Wimix supports the following internal and external commands:

### Internal Commands
- `cd [dir]`: Change the current working directory to `dir`. If no argument is given, change to the home directory.
- `echo [args]`: Print the arguments to the standard output, separated by spaces.
- `pwd`: Print the current working directory to the standard output.
- `exit`: Exit the shell.

### External Commands
- `ls [-a] [-l] [dir]`: List the files and directories in `dir` or the current working directory. The `-a` option shows hidden files and directories. The `-l` option shows detailed information such as permissions, size, owner, group, and modification time.
- `cat [-n] [file]`: Print the contents of `file` to the standard output. The `-n` option shows line numbers.
- `date [+format]`: Print the current date and time to the standard output. The optional `format` argument specifies how to format the output using placeholders such as `%Y` for year, `%m` for month, `%d` for day, `%H` for hour, `%M` for minute, and `%S` for second. For example, `date +%Y-%m-%d` prints the date in YYYY-MM-DD format.
- `rm [-r] [file]`: Remove (delete) `file` or directory. The `-r` option recursively removes directories and their contents.
- `mkdir [dir]`: Create a new directory named `dir`.

To execute any of these external commands in a thread-based manner, append `&t` to the command. For example, `ls -l &t` will create a new thread to run the `ls -l` command and return to the prompt immediately.

## Test Cases
To test the functionality of Wimix, you can try some of these test cases:

- Run `pwd` to see your current working directory.
- Run `cd ..` to go up one level in the directory hierarchy.
- Run `echo Hello World!` to print “Hello World!” to the standard output.
- Run `ls -a -l /etc` to list all files and directories in `/etc` with detailed information.
- Run `cat -n /etc/passwd` to print the contents of `/etc/passwd` with line numbers.
- Run `date +%H:%M:%S` to print the current time in HH:MM:SS format.
- Run `rm -r testdir` to remove a directory named “testdir” and its contents (if it exists).
- Run `mkdir newdir` to create a new directory named “newdir”.
- Run `ls &t; date &t; pwd &t; echo Done! &t; wait` to execute four commands in parallel threads and wait for them to finish.

## Errors Handled
Wimix handles some of the common errors and corner cases that may occur while using the shell. Some of them are:

- Invalid command: If the user types a command that is not supported by Wimix, the shell will print an error message and return to the prompt.
- Invalid option: If the user types an option that is not valid for a command, the shell will print an error message and return to the prompt.
- Missing argument: If the user types a command that requires an argument but does not provide one, the shell will print an error message and return to the prompt.
- Invalid argument: If the user types an argument that is not valid for a command, such as a non-existent file or directory, the shell will print an error message and return to the prompt.
- Permission denied: If the user tries to access or modify a file or directory that they do not have permission to, the shell will print an error message and return to the prompt.
- Thread creation failure: If the shell fails to create a new thread for an external command with `&t`, the shell will print an error message and return to the prompt.

## Assumptions Made
Wimix makes some assumptions about the environment and the user input. Some of them are:

- The user has a Linux system with GCC, Make, and POSIX threads library installed.
- The user has cloned or downloaded the source code of Wimix and navigated to its directory.
- The user has compiled and installed Wimix using `make` and `make install`.
- The user types commands in lowercase letters and separates arguments by spaces.
- The user does not type more than one command in a single line.
- The user does not type more than 256 characters in a single line.

## References
- [Linux Manpages](https://linux.die.net/man/)
