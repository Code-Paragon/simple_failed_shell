#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av, char **env) {
    char *path;
    char *token;
    char *delim = ":";
    char *file;

    path = getenv("PATH");
    
    if (path == NULL) {
        printf("PATH environment variable not set.\n");
        return 1;
    }

    char *path_copy = strdup(path);  // Create a copy of PATH to avoid modifying the original
    if (path_copy == NULL) {
        perror("Memory allocation error");
        return 1;
    }

    token = strtok(path_copy, delim);

    while (token != NULL)
    {
        char *file = (char *)malloc(strlen(token) + strlen("/ls") + 1);
        if (file == NULL) {
            perror("Memory allocation error");
            return 1;
        }

        strcpy(file, token);
        strcat(file, "/ls");

        printf("%s\n", file);

        free(file);

        token = strtok(NULL, delim);
    }

    free(path_copy);

    return 0;
}