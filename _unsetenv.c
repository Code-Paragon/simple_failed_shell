#include "main.h"
ldpwd);
int com_unsetenv(char **args, char __attribute__((__unused__)) **front)
{
	char **new_env, **environ_var;
	int idx, idx2;
	size_t s;
	if (!args[1])
	{
		perror("args error at unsetenv");
		return (-1);
	}
	environ_var = _getenv(args[1]);
	if (!environ_var)
		return (0);
	for (s = 0; environ[s]; s++)
	{}
	new_env = malloc(sizeof(char *) * s);
	if (!new_env)
	{
		free(*environ_var);
		perror("new_env malloc failed at unsetenv");
		return (-1);
	}
	for (idx = 0, idx2 = 0; environ[idx]; idx++)
	{
		if (*environ_var == environ[idx])
		{
			free(*environ_var);
			continue;
		}
		new_env[idx2] = environ[idx];
		idx2++;
	}
	free(environ);
	environ = new_env;
	environ[s - 1] = NULL;
	return (0);
}
