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
    return output;
}

int exec_command(char * command){
    command = trim(command);
    char ** args = parse_args(command, " ");
    int i=0;
    /*
    //debugging purposes
    while(args[i] != NULL){
        printf("This is one element of the command:%s\n", args[i]);
        i++;
    }
    */
    pid_t pid = fork();
    if (pid == -1){
        printf("Failed\n");
        return 0;
    } else if (!pid){
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
