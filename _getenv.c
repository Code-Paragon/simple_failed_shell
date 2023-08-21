#include "main.h"

extern char **environ;
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strdup(char *str);
/**
 * _getenv - gets an environment variable's value. (without using getenv)
 * @name: name of variable
 *
 * Return: 0
 */
char *_getenv(char *name)
{
	int i = 0;
	char *token, *copy, delim[] = "=";

	while (environ[i])
	{
		copy = _strdup(environ[i]);
		token = _strtok(copy, delim);
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
