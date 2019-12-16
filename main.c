#include "header.h"

int main(int argc, char *argv[]){
  while(1){
    char *line;
    char buffer[100];
    printf("shell$ ");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = 0;
    if (exec_multiple(buffer) == 1){
      return 0;
    }
  }
  return 0;
}
