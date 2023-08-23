#include "main.h"
/**
 * com_cd - Changes the current directory
 * @args: an array of arguments
 * @front: double pointer to the beginning of args
 *
 * Return: If the given string is not a directory - 2
 * If an error occurs - -1Otherwise - 0.
 */
int com_cd(char **args, char __attribute__((__unused__)) **front)
{
	/* struct stat dir ; */
	char *newLine = "\n", **direc_inf;
	char *pwd = NULL, *oldpwd = NULL;

	oldpwd = getcwd(oldpwd, 0);
	if (!oldpwd)
		return (-1);
	if (args[0])
	{
		if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||args[0][1] == '\0')
			{
				if (_getenv("OLDPWD") != NULL)
					(chdir(*_getenv("OLDPWD") + 7));
			}
			else
			{
				free(oldpwd);
				free(pwd);
				return (-1);
			}
		}
	}
	else
	{
		if (_getenv("HOME") != NULL)
			chdir(*(_getenv("HOME")) + 5);
	}
	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);
	direc_inf = malloc(sizeof(char *) * 2);
	if (!direc_inf)
		return (-1);
	direc_inf[0] = "OLDPWD";
	direc_inf[1] = oldpwd;
	if (com_setenv(direc_inf, direc_inf) == -1)
		return (-1);
	direc_inf[0] = "PWD";
	direc_inf[1] = pwd;
	if (com_setenv(direc_inf, direc_inf) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, newLine, 1);
	}
	free(oldpwd);
	free(pwd);
	free(direc_inf);
	return (0);
}
