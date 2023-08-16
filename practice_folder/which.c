#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
char *handle_path(char *command);

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

        printf("%s\n", file);

		if (stat(file, &sb) == 0)
			return (file);

        free(file);

        token = strtok(NULL, delim);
    }

    free(path_copy);

    return (NULL);
}

int main(){
	char *c_path;

	c_path = handle_path("sd");

	printf("%s/n", c_path);

	return (0);
}

