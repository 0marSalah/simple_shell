#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;

    while (1) {
        printf(":) ");
        nread = getline(&line, &len, stdin);
        if (nread == -1) {
            if (feof(stdin)) {
                printf("\n");
                exit(EXIT_SUCCESS);
            } else {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        // Remove newline character from input
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }

        // Parse the input into tokens
        char **args;
        args = parse_args(line);
        
        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting shell...\n");
            exit(EXIT_SUCCESS);
        }

        run_command(args);
    }

    free(line);
    exit(EXIT_SUCCESS);
}
