#include "main.h"

/**
 * execute - checks if the command is a path and runs it
 *
 * @fraginputstr: tokenised string from user
 * @envp: environmental variable
 *
 * Return: -1
 */

int execute(char *fraginputstr[], char *const envp[])
{
	char *command = fraginputstr[0];
	char *fullpath;

	if (command[0] != '/')
	{
		fullpath = handle_path(command);

		if (fullpath != NULL)
		{
			if (execve(fullpath, fraginputstr, envp) == -1)
			{
				perror("./hsh");
			}
		}
	}
	else
	{
		if (execve(command, fraginputstr, envp) == -1)
		{
			free(fraginputstr);
		}
	}

	return (-1);
}
