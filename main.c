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
  int y = getppid();
  int k;
  int i;
  if (f == 0){
    printf("Child");
    execvp(arg_array[0], arg_array);
  } else if (f > 0){
    if ((x = wait(&k)) < 0){
      printf("error");
      exit(0);
    }
    printf("finished");
  } else{
    printf("failed");
  }
/*  for (i = 0; i < sizeof(arg_array)/sizeof(arg_array[0]); i++){
    execvp(arg_array[0], arg_array);
  } */

}
