#include "main.h"

/**
 * hadle_path - generates directory for command
 * @command: argument path to be found
 * 
 * Return: NULL
*/

char *handle_path(char *command) {
    char *path;
    char *token;
    char *delim = ":";
    char *file;
	struct stat sb;

    path = getenv("PATH");
    
    if (path == NULL) {
        printf("PATH environment variable not set.\n");
        return NULL;
    }

    char *path_copy = strdup(path);  // Create a copy of PATH to avoid modifying the original
    if (path_copy == NULL) {
        perror("Memory allocation error");
        return NULL;
    }

    token = strtok(path_copy, delim);

    while (token != NULL)
    {
        char *file = (char *)malloc(strlen(token) + strlen(command) + 2);
        if (file == NULL) {
            perror("Memory allocation error");
            return NULL;
        }

        strcpy(file, token);
        strcat(file, "/");
        strcat(file, command);

		if (stat(file, &sb) == 0)
			return (file);

        free(file);

        token = strtok(NULL, delim);
    }

    free(path_copy);

    return (NULL);
}
