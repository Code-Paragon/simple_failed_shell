#include "main.h"

/**
 * _printenv - prints the environment variables
 * 
 * Return: 0
 */
int _printenv(void)
{
	char **env;

	/* Loop through the environment variables and print them */
	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}

	return (0);
}
