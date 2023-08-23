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

	if (!args[0] || !args[1])
	{
		perror("args incomplete at setenv");
		free(*environ_var);
		return (-1);
	}
	/* Allocate memory for the new value (environment variable=value) */
	new_envValue = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_envValue)
	{
		perror("new_envValue malloc failed at setenv");
		free(new_envValue);
		free(*environ_var);
		return (-1);
	}
	/* Concantenate the provided var name and its value with = in between */
	_strcpy(new_envValue, args[0]);
	_strcat(new_envValue, "=");
	_strcat(new_envValue, args[1]);
	/* Check if the environment variable already exists */
	environ_var = _getenv(args[0]);
	if (environ_var)
	{
		/* If it exists, update its value */
		free(*environ_var);
		*environ_var =  new_envValue;
		return (0);
	}
	 /* Count the number of existing environment variables */
	for (s = 0; environ[s]; s++)
	{}
	/* Allocate memory for the new environment array */
	new_env = malloc(sizeof(char *) * (s + 2));
	if (!new_env)
	{
		free(*new_env);
		perror("new_envValue malloc failed at setenv");
		free(new_envValue);
		free(*environ_var);
		return (-1);
	}
	/* Copy existing environment variables to the new array */
	for (idx = 0; environ[idx]; idx++)
		new_env[idx] = environ[idx];
	/* Update the environment array to use the new array */
	free(environ);
	environ = new_env;
	environ[idx] = new_envValue;
	environ[idx + 1] = NULL;
	return (0);
}
