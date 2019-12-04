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
