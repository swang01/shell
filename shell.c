#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>

char ** parse_args(char * line, char * delimiter){
  char ** args = malloc(6 * sizeof(char *));
  int i = 0;
  while (line != NULL){
    args[i] = strsep(&line, delimiter);
    i++;
  }
  args[i] = NULL;
  return args;
}

static void sighandler(int signo){
  if (signo == SIGINT){
    printf("Terminated");
    exit(0);
  }
}
