#include "main.h"
#include <stdlib.h>
int create_process(char *fraginputstr[], char *const envp[]);
int (*get_Plugin(char *command))(char **args, char **front);
char **_prompt(char *inputstr, char *fraginputstr[]);

/**
 * shell - the main shell
 * @inputstr: usr input
 * @envp: process environ
 * @args: argument array
 * @front: pointer to front of arg arr
 *
 * Return: 1 error, 0 success
 */
int shell(char *const envp[], char *inputstr,
	char **args, char __attribute__((__unused__)) **front)
{
	char *fraginputstr[1000];
	int (*Plugin_function)(char **args, char **front);

	while (1)
	{
		_prompt(inputstr, fraginputstr);
		if (fraginputstr[0] != NULL)
		{
			if (_strcmp(fraginputstr[0], "exit") == 0)
				shell_exit(fraginputstr);
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

/**
 * tok_inputstr - prints prompt and tokenise inputstr
 * @inputstr: input string
 * @fraginputstr: array of input string
 * 
 * Return: fraginputstr on success 
 */
char **tok_inputstr(char *inputstr, char *fraginputstr[])
{
	size_t len = 100;
	char delim[] = " \n\t";
	int y = 0;
	ssize_t Firstwrite, read = 1;
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
		return (fraginputstr);
}
