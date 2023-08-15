#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;
/**
 * _getenv - gets an environment variable. (without using getenv)
 *
 * Return: 0
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *token, *copy, delim[] = "=";

	while (environ[i])
	{
		copy = strdup(environ[i]);
		token = strtok(copy, delim);
		if (token != NULL && strcmp(name, token) == 0)
		{
			free(copy);
			return strchr(environ[i], '=') + 1;
		}
		free(copy);
		i++;
	}
	return (NULL);
}

int main(void)
{
	char *path = _getenv("PATH"), *token;
	char delim[] = ":";

	if (path)
	{
	token = strtok(path, delim);
	while (token != NULL)
	{
		printf("PATH: %s\n", token);
		token = strtok(NULL, delim);
	}
	}
	else
	{
		printf("PATH not found.\n");
	}
	
	return 0;
}
