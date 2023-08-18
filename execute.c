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
			execve(fullpath, fraginputstr, envp);
			perror("execve");
		}
	}
	else
	{
		execve(command, fraginputstr, envp);
		perror("execve");
	}

	return (-1);
}
