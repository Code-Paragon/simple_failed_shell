#include "main.h"
char *search_file_path(char *command, char *token);

/**
 * handle_path - generates directory for command
 * @command: argument path to be found
 *
 * Return: NULL
 */

char *handle_path(char *command)
{
	char *path, *path_copy;
	char *token;
	char *delim = ":";

	path = *(_getenv("PATH"));

	if (path == NULL)
	{
		write(1, "PATH environment variable not set.\n", 34);
		return (NULL);
	}

	/* Create a copy of PATH to avoid modifying the original */
	path_copy = _strdup(path);

	if (path_copy == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}

	token = _strtok(path_copy, delim);

	while (token != NULL)
	{
		char *file_path = search_file_path(command, token);

		if (file_path != NULL)
		{
			free(path_copy);
			return (file_path); /* Return the found path */
		}
		token = _strtok(NULL, delim);
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

	file = malloc(_strlen(token) + _strlen(command) + 2);
	if (file == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}

	_strcpy(file, token);
	_strcat(file, "/");
	_strcat(file, command);

	if (stat(file, &sb) == 0)
		return (file);

	free(file);
	return (NULL);
}
