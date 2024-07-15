# Custom Shell in C

## Overview
This project is a Unix-like shell implemented in C that can handle a set of basic commands. The shell supports commands such as `pwd`, `cd`, `echo`, `cat`, `rm`, `mkdir`, `ls`, and `date`, providing a simple yet functional command-line interface.

## Features
1. **Command Support**: Handles basic Unix commands including:
    - `pwd`: Print working directory
    - `cd`: Change directory
    - `echo`: Display a line of text
    - `cat`: Concatenate and display file content
    - `rm`: Remove files
    - `mkdir`: Create directories
    - `ls`: List directory contents
    - `date`: Display the current date and time
2. **Robust Command Parsing**: Efficiently parses and executes user commands with support for various command-line arguments and options.
3. **Error Handling**: Provides clear error messages for invalid commands and operations, enhancing user experience and debugging.

## Usage
Clone the repository and compile the shell using `gcc`:
```sh
git clone https://github.com/aryan21454/custom-shell.git
cd custom-shell
gcc -o custom_shell shell.c
./custom_shell
