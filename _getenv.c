#include "main.h"

int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
/**
 * _getenv - gets an environment variable's value. (without using getenv)
 * @name: name of variable
 *
 * Return: 0
 */
char **_getenv(char *name)
{
	int index;
	size_t len = _strlen(name);

	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(name, environ[index], len) == 0)
			return (&environ[index]);
	}

	return (NULL);
}
