# shell
by Steve Wang and Yifan Wang

# Features:
  - Forks and executes commands
  - Parses multiple commands on one line
  - Changes directory
  
# Attempted
  - exit runs, but does not exit out of the shell
  - Tried to implement redirection and piping, but doesn't work ("No such file or 
  directory").
  
# Bugs
  - Putting two ;'s next to each other runs the commands on both sides, but also tries   running the ; and thus prints "Could not execute."
  - Putting more than 1 space between the command and its arguments does not run the 
  command.
  - Putting >> does not work
  - Makefile error when exiting out of the program
  
  
 # Function Headers
```
static void sighandler(int signo)

Input: int signo
Output: void, if the signo is SIGINT it exits the process
Description: Prints "terminated" in the shell and exits the
shell
```
```
char ** parse_args(char * line, char * delimiter)

Input: char * line, char * delimiter
Output: A pointer to an array of pointers of chars of items
of a line of command
Description: Separates a line of command by the specified
delimiter
```
```
char * trim(char * str)

Input: char * str
Output: A pointer to an array of chars of items of edited line
of command
Description: Edits extra space in the beginning or end of line of
command to allow the format "command ; command"
```
```
void redirect_in(char * line)

Input: char * line
Output: void, performs redirect in
Description: Takes in a command line that intends for redirect in,
parses the line and performs the redirection
```
```
void redirect_out(char * line)

Input: char * line
Output: void, performs redirect out
Description: Takes in a command line that intends for redirect out,
parses the line and performs the redirection
```
```
void redirect_out(char * line)

Input: char * command
Output: An int indicating the process has successfully ran
Description: Takes in a command line that intends for piping,
parses the line and performs the piping
```
```
void changeDir(char * command)

Input: char * command
Output: Void, performs what "cd" does in a regular shell
Description: Takes in a command line, parses the command and performs
the corresponding cd command
```
```
int exec_command(char * command)

Input: char * command
Output: An int indicating that the process ran successfully
Description: Executes a line of single command, without ";"
```
```
int exec_multiple(char * command)

Input: char * command
Output: An int indicating that the process ran successfully
Description: Executes a line of multiple commands, separated by ";"
```

