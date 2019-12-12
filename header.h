#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>

char ** parse_args(char * line, char * delimiter);
static void sighandler(int signo);
void exec_command(char * command);
int exec_multiple(char * command);
