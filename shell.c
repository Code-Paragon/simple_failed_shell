#include "main.h"
#include <stdlib.h>
int create_process(char *fraginputstr[], char *const envp[]);
int (*get_Plugin(char *command))(char **args, char **front);

/**
 * shell - the main shell
 * @inputstr: usr input
 * @envp: process environ
 *
 * Return: 1 error, 0 success
 */
int shell(char *const envp[], char *inputstr,char **args, char __attribute__((__unused__)) **front)
{
	ssize_t read = 1, Firstwrite;
	size_t len = 100;
	char delim[] = " \n\t";
	char *fraginputstr[1000];
	int y = 0;
	int (*Plugin_function)(char **args, char **front);

	while (1)
	{
		Firstwrite = write(1, "($) ", 4);
		if (Firstwrite < 0)
			perror("write failed");
		read = _getline(&inputstr, &len, stdin);
		if (read != -1)
		{
			y = 0;
			fraginputstr[y] = _strtok(inputstr, delim);
			while (fraginputstr[y] != NULL)
			{
				y++;
				fraginputstr[y] = _strtok(NULL, delim);
			}
		}
		else /* Check for custom EOF i.e Crtl+D */
		{
			free(inputstr);
			write(1, "\n", 1);
			exit(0);
		}

		Plugin_function = get_Plugin(fraginputstr[0]);
		if (Plugin_function != NULL)
		{
			Plugin_function(fraginputstr, args);
		}
		else
			create_process(fraginputstr, envp);
		
	}
	free(inputstr);
	return (0);
}

/**
 * create_process - creates a child process
 * @fraginputstr: fragmented input string
 * @envp: process environ
 *
 * Return: 1 error, 0 success
 */
int create_process(char *fraginputstr[], char *const envp[])
{
	pid_t my_pid = 1;

	my_pid = fork();

	if (my_pid == -1)
	{
		perror("fork failed");
		return (0);
	}

	else if (my_pid == 0)
	{
		if (execute(fraginputstr, envp) != -1)
			perror("./hsh");

		free(fraginputstr);
		exit(0);
	}
	else
		wait(NULL);

	return (0);
}
