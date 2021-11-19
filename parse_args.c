#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include "parse_args.h"

// TODO: cd, exit, recieve input, check for semicolon

// int main() {
//   char cmd[] = "ls -a -l -d -b -i";
//   execute(cmd);
//   return 0;
// }

void execute_cmd(char *line) {
  int i = 0;
  char **args;
  args = malloc(sizeof(char *) * 5);
  char *curr = line;
  char *token;
  //printf("a\n");
  while (curr) {
    token = strsep(&curr, " ");
    args[i] = token;
    // printf("Argument %d: %s\n", i+1, token);
    i++;
  }
  if (i > 5) args = realloc(args, sizeof(char *) * i);
  execvp(args[0], args);
  free(args);
}
