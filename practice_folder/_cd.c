#include "main.h"
int _strcmp(char *s1, char *s2);
int update_env_vars(char *name, char *value);
/**
 * update_env_vars - updating environment variables
 * @name: name
 * @value: value
 *
 * Return: int
 */
{
	char **env_update = malloc(sizeof(char *) * 2);
	if (env_update == NULL)
	{
		perror("malloc failed");
        return -1;
    }
    
    env_update[0] = name;
    env_update[1] = value;

    if (com_setenv(env_update, env_update) == -1) 
	{
        free(env_update);
	    return -1;
    }

    free(env_update);
    return 0;
}
/**
 * com_cd - Changes the current directory
 * @args: an array of arguments
 * @front: double pointer to the beginning of args
 *
 * Return: If the given string is not a directory - 2
 * If an error occurs - -1Otherwise - 0.
 */
int com_cd(char **args, char __attribute__((__unused__)) * *front)
{
	struct stat direc;
	char *newLine = "\n", **direc_inf;
	char *pwd = NULL, *oldpwd = NULL;

	oldpwd = getcwd(oldpwd, 0);
	if (!oldpwd)
	{
		free(oldpwd);
		return (-1);
	}
	if (args[1])
	{
		if (*(args[1]) == '-' || _strcmp(args[1], "--") == 0)
		{
			if ((args[1][2] == '-' && args[1][3] == '\0') || args[1][2] == '\0')
			{
				if (_getenv("OLDPWD") != NULL)
					(chdir(*_getenv("OLDPWD") + 7));
			}
			else
			{
				free(oldpwd);
				return (-1);
			}
		}
		else
		{
			if (stat(args[1], &direc) == 0 && S_ISDIR(direc.st_mode) && ((direc.st_mode & S_IXUSR) != 0))
            {
                if (chdir(args[1]) == -1)
                {
                    return (-1);
                }

                update_env_vars("OLDPWD", oldpwd);
                char *pwd = getcwd(NULL, 0);
                update_env_vars("PWD", pwd);
                free(pwd);
            }
            else
            {
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
	{
		free(pwd);
		return (-1);
	}
	direc_inf = malloc(sizeof(char *) * 2);
	if (!direc_inf)
	{
		free(direc_inf[0]);
		free(direc_inf[1]);
		return (-1);
	}
	direc_inf[0] = "OLDPWD";
	direc_inf[1] = oldpwd;
	if (com_setenv(direc_inf, direc_inf) == -1)
	{
		free(direc_inf[0]);
		free(direc_inf[1]);
		return (-1);
	}
	direc_inf[0] = "PWD";
	direc_inf[1] = pwd;
	if (com_setenv(direc_inf, direc_inf) == -1)
	{
		free(direc_inf[0]);
		free(direc_inf[1]);
		return (-1);
	}
	if (args[1] && args[1][1] == '-' && args[1][2] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, newLine, 1);
	}
	free(oldpwd);
	free(pwd);
	free(direc_inf);
	return (0);
}
