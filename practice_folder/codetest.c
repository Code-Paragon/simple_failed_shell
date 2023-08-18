#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

char *search_file_path(char *command, char *token);

/**
 * handle_path - generates directory for command
 * @command: argument path to be found
 *
 * Return: NULL
 */

char *handle_path(char *command)
{
	char *path;
	char *token;
	char *delim = ":";

	path = getenv("PATH");

	if (path == NULL)
	{
		printf("PATH environment variable not set.\n");
		return (NULL);
	}

	/* Create a copy of PATH to avoid modifying the original */
	char *path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}

	token = strtok(path_copy, delim);

	while (token != NULL)
	{
		char *result = search_file_path(command, token);

		if (result != NULL)
		{
			free(path_copy);
			return result; // Return the found path
		}

		token = strtok(NULL, delim);
	}

	free(path_copy);
	return (NULL);
}

/**
 * search_file_path - checks if the command inputed as a path
 * @command: argument path to be found
 * @token: directory path
 *
 * Return: NULL
 */

char *search_file_path(char *command, char *token)
{
	struct stat sb;
	char *file;

	file = malloc(strlen(token) + strlen(command) + 2);
	if (file == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}

	strcpy(file, token);
	strcat(file, "/");
	strcat(file, command);

	if (stat(file, &sb) == 0)
	{
		printf("%s\n", file);
		return (file);
	}

	free(file);
	return (NULL);
}

int main()
{
	char *command = "ls";
	char *result = handle_path(command);

	if (result != NULL)
	{
		// Use the result as needed
		printf("Found command: %s\n", result);
		free(result); // Don't forget to free the memory
	}
	else
	{
		printf("Command not found.\n");
	}

	return (0);
}
