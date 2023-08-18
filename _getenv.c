#include "main.h"
extern char **environ;
/**
 * _getenv - gets an environment variable's value. (without using getenv)
 * @name: name of variable
 *
 * Return: 0
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *token, *copy, delim[] = "=";

	while (environ[i])
	{
		copy = _strdup(environ[i]);
		token = strtok(copy, delim);
		if (token != NULL && _strcmp(name, token) == 0)
		{
			free(copy);
			return _strchr(environ[i], '=') + 1;
		}
		free(copy);
		i++;
	}
	return (NULL);
}
