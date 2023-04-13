#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024

/*  
  *  This program is a simple shell that executes commands.
  *  It will prompt the user for a command and then execute it.
  *  If the command is not found, it will print an error message.
  *  If the command is found, it will fork a child process to execute it.
  *  The parent process will wait for the child to finish.
  *  The program will continue to prompt the user for commands until
  *  the user enters an empty line.
*/

int main(void)
{
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;
  pid_t pid;
  int status;

  printf("Welcome to the shell!\n");
  printf("Enter a CTR+d to exit.\n");

  while (1) {
      printf("$ ");
      nread = getline(&line, &len, stdin); // return number of chars
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

      pid = fork();
      if (pid == -1) {
          perror("fork");
          exit(EXIT_FAILURE);
      } else if (pid == 0) {
          // Child process
          execlp(line, line, NULL);
          perror("exec");
          exit(EXIT_FAILURE);
      } else {
          // Parent process
          wait(&status);
      }
  }

  free(line);
  exit(EXIT_SUCCESS);
}

