#include "main.h"

#define MAX_ARGS 64

/*  
  * parse_args - parse a line into an array of arguments
  * @line: the line to parse
  * 
  * Return: an array of arguments
*/

char** parse_args(char* line) {
    char **args = malloc(64 * sizeof(char *));
    if (args == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char *token;
    int i = 0;
    token = strtok(line, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    return args;
}
