#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

/** prototypes **/

char** token_command(char *command);
int main(void);
int command_execute(char **args);

#endif /* SHELL_H */
