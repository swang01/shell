#include "header.h"

int main(int argc, char *argv[]){
  while(1){
    char *line;
    char buffer[100];
    printf("shell$ ");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = 0;
    line = buffer;
    char ** arg_array;
    exec_command(buffer);
  }
  return 0;

    /* char *line;
    char buffer[100];
    printf("shell$ ");
    fgets(buffer, 100, stdin);
    buffer[strlen(buffer) - 1] = 0;
    line = buffer;
    char ** arg_array;
    arg_array = parse_args(line,";");
    if (errno){
        printf("errno: %d; error: %s\n", errno, strerror(errno));
    }
    int i = 0;

    //checking if parse_args correctly separated list of commands
    while(arg_array[i] != NULL){
        printf("%s\n", arg_array[i]);
        i++;
    }

    char ** arg_array2;
    int a = 0;
    while(arg_array[a] != NULL){
        printf("-----\n");
        arg_array2 = parse_args(arg_array[a], " ");
        execvp(arg_array2[0], arg_array2);
        /**
        int b = 0;
        while (arg_array2[b] != NULL){
            int f = fork();
            int x;
            int status;
            if (f == 0){
                printf("child\n");
                execvp(arg_array2[b], arg_array2);
                printf("execvp failed\n");
            } else if (f > 0){
                if ((x = wait(&status)) < 0){
                    printf("error\n");
                    exit(0);
                }
                printf("finished\n");
            } else{
                printf("failed\n");
            }
            b++;
        }
        **/
        a++;
    }
    return 0;
    for (i = 0; i < sizeof(arg_array)/sizeof(arg_array[0]); i++){
        execvp(arg_array[0], arg_array);
    }
}
