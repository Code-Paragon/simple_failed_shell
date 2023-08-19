#include <stdio.h>

extern char **environ;

/**
 * main - prints the environment using the global variable environ
 *
 * Return: 0
 */
int main (int ac, char **av, char **env)
{
	int i = 0;

	for (char **envi = environ; *envi != NULL; envi++)
	{
		printf("%s\n", *envi);
	}
	printf("\n\n\n");
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
