#include "main.h"
/**
 * shellby_setenv - Changes or adds an environmental variable to the PATH.
 * @args: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of args.
 * Description: args[1] is the name of the new or existing PATH variable.
 * args[2] is the value to set the new or changed variable to.
 *
 * Return: If an error occurs - -1, Otherwise - 0.
 */
int com_setenv(char **args, char __attribute__((__unused__)) **front)
{
	size_t s;
	int idx;
	char **new_env, *new_envValue, **environ_var = NULL;

	if (!args[1] || !args[2])
	{
		perror("args incomplete at setenv");
		return (-1);
	}
	new_envValue = malloc(_strlen(args[1]) + 1 + _strlen(args[2]) + 1);
	if (!new_envValue)
	{
		perror("new_envValue malloc failed at setenv");
		return (-1);
	}
	_strcpy(new_envValue, args[1]);
	_strcat(new_envValue, "=");
	_strcat(new_envValue, args[2]);
	environ_var = _getenv(args[1]);
	if (environ_var)
	{
		free(*environ_var);
		*environ_var =  new_envValue;
		return (0);
	}
	for (s = 0; environ[s]; s++)
	{}
	new_env = malloc(sizeof(char *) * (s + 2));
	if (!new_env)
	{
		perror("new_envValue malloc failed at setenv");
		free(new_envValue);
		return (-1);
	}
	for (idx = 0; environ[idx]; idx++)
		new_env[idx] = environ[idx];
	free(environ);
	environ = new_env;
	environ[idx] = new_envValue;
	environ[idx + 1] = NULL;
	return (0);
}
