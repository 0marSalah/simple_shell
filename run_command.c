#include "main.h"

void run_command(char **args) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("error: unexpected command");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        wait(NULL);
    }
}
