#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>

char ** parse_args(char * line){
  char ** args = malloc(5 * sizeof(char *));
  char * curr = line;
  int i = 0;
  while (line != NULL){
    args[i] = strsep(&line," ");
    i++;
  }
  args[i] = NULL;
  return args;
}

static void sighandler(int signo){
  if (signo == SIGINT){
    exit(0);
  }
}
