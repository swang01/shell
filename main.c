#include "header.h"

int main(int argc, char *argv[]){
  char *line;
  char buffer[100];
  printf("shell$ ");
  fgets(buffer, 100, stdin);
  buffer[strlen(buffer) - 1] = 0;
  line = buffer;
  char ** arg_array;
  arg_array = parse_args(line);
  int f = fork();
  int x = getpid();
  execvp(arg_array[0], arg_array);
  wait(&x);

}
