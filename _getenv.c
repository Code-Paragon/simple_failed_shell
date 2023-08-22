#include "main.h"

int _strcmp(char *s1, char *s2);
/**
 * _getenv - gets an environment variable's value. (without using getenv)
 * @name: name of variable
 *
 * Return: 0
 */
char **_getenv(char *namme)
{
	int idx;

	for (idx = 0; environ[idx]; idx++)
	{
		if (_strncmp(name, environ[idx]) == 0)
			return (&environ[idx]);
	}

	return (NULL);
}
