#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>

static void sighandler(int signo){
    if (signo == SIGINT){
        printf("Terminated\n");
        exit(0);
    }
}

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

char * trim(char * str) {
    int i,j;
    char * output = str;
    if (str[0] == ' '){
        for(i = 1, j = 0; j < strlen(str); i++, j++) {
            output[j] = str[i];
        }
    }
    if (str[strlen(str)-1] == ' '){
        output[strlen(str)-1] = 0;
    }
    for (i = 0; i < strlen(str); i++){
        if(str[i] == ' ' && str[i+1] == ' '){
            for(j = i; j < strlen(str); i++, j++) {
                output[j] = str[i+1];
            }
        }
    }
    return output;
}

int exec_command(char * command){
    command = trim(command);
    printf("%s\n", command);
    char ** args = parse_args(command, " ");
    //debugging
    int i=0;
    while(args[i] != NULL){
        i++;
    }
    pid_t pid = fork();
    if (pid == -1){
        printf("Failed\n");
        return 0;
    } else if (pid == 0){
      if (strchr(command, '<') != NULL){
        redirect_in(command);
      }
      if (strchr(command, '>') != NULL){
        redirect_out(command);
      }
      if (strchr(command, "|") != NULL){
        pipes(command);
      }
      if (strcmp(args[0], "exit") == 0) exit(0);
        if (execvp(args[0], args) < 0){
            printf("Could not execute\n");
        }
        exit(0);
    } else {
        wait(NULL);
        return 0;
    }
}

int exec_multiple(char * command){
    char ** args = parse_args(command, ";");
    int i = 0;
    while(args[i] != NULL){
        exec_command(args[i]);
        i++;
    }
    return 0;
}

void redirect_in(char * line){
  char ** parsed = parse_args(line, "<");
  char ** args = parse_args(args[0], " ");
  int fd = open(parsed[1], O_RDONLY, 0644);
  dup(STDIN_FILENO);
  dup2(fd, STDIN_FILENO);
  execvp(args[0], args);
  printf("Failed\n");
  close(fd);
  exit(1);
}

void redirect_out(char * line){
  char ** parsed = parse_args(line, ">");
  char ** args = parse_args(args[0], " ");
  int fd = open(parsed[1], O_CREAT | O_WRONLY, 0644);
  dup(STDOUT_FILENO);
  dup2(fd, STDOUT_FILENO);
  execvp(args[0], args);
  printf("Failed\n");
  close(fd);
  exit(1);
}

int pipes(char ** args){
  char * input  = args[0];
    char * output = args[1];
    char line[256];
    char cmd[256];
    FILE *read = popen(input,"r");
    while (fgets(line,256,read)) {
      line[sizeof(line)-1] = 0;
      strcat(cmd,line);
    }
    pclose(read);
    FILE *write = popen(output,"w");
    fprintf(write,"%s",cmd);
    pclose(write);
    return 0;
}
