#ifndef SIMPLE_SHELL_MAIN_H
#define SIMPLE_SHELL_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

char** parse_line_to_args(char* line);
void run_command(char **args);
char *_getline(void);

#endif
