#include "header.h"

int main(int argc, char *argv[]){
    char *line;
    char buffer[100];
    printf("shell$ ");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = 0;
    line = buffer;
    char ** arg_array;
    arg_array = parse_args(line,";");
    if (errno){
      printf("errno %d error %s\n", errno, strerror(errno));
    }
    char ** arg_array2;
    int a;
    int b;
    for (a = 0; a < sizeof(arg_array)/sizeof(char *); a++){
      arg_array2 = parse_args(arg_array[a], " ");
      b = 0;
      while (arg_array2[b] != NULL){
        int f = fork();
        int x;
        int y = getppid();
        int status;
        int i;
        if (f == 0){
          printf("Child\n");
          execvp(arg_array[0], arg_array);
          printf("execvp failed");
        } else if (f > 0){
          if ((x = wait(&status)) < 0){
            printf("error");
            exit(0);
          }
          printf("finished");
        } else{
          printf("failed");
        }
        b++;
      }
    }
    return 0;
/*  for (i = 0; i < sizeof(arg_array)/sizeof(arg_array[0]); i++){
    execvp(arg_array[0], arg_array);
  } */

}
