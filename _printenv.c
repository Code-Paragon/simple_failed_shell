#include "main.h"

/**
 * com_env - prints the environment variables
 * @args: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *	   Otherwise - 0.
 *
 * Description: Prints one variable per line in the
 *              format 'variable'='value'.
 */
int com_env(char **args, char __attribute__((__unused__)) **front);
{
	char nch = '\n';
	int idx;

	if (!environ)
		return (-1);
/* Loop through the environment variables and print them */
	for (idx = 0; environ[idx]; idx++)
	{
		write(STDOUT_FILENO, environ[idx], _strlen(environ[index]));
		write(STDOUT_FILENO, &nch, 1);
	}

	(void)args;
	return (0);
}
