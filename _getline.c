#include "main.h"

#define BUFFER_SIZE 1024

/*  
  * _getline - read a line from stdin
  * 
  * Return: a line from stdin
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    ssize_t bytes_read = 0;
    char *buffer = NULL;
    size_t buffer_size = 0;
    size_t line_size = 0;
    char *line = NULL;
    char *tmp = NULL;

    if (lineptr == NULL || n == NULL || stream == NULL)
        return (-1);

    buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if (buffer == NULL)
        return (-1);

    while ((bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        tmp = realloc(line, line_size + bytes_read + 1);
        if (tmp == NULL)
        {
            free(line);
            free(buffer);
            return (-1);
        }
        line = tmp;
        _strcat(line, buffer);
        line_size += bytes_read;
        if (buffer[bytes_read - 1] == '\n')
            break;
    }
    free(buffer);
    *lineptr = line;
    *n = line_size;
    return (bytes_read);
}
