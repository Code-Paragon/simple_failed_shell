#include <stdio.h>

extern char **environ;

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
