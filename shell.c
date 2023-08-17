#include "main.h"
int create_process(char *fraginputstr[], char *const envp[]);

/**
 * shell - the main shell
 * @inputstr: usr input
 * @envp: process environ
 *
 * Return: 1 error, 0 success
 */
int shell(char *const envp[], char *inputstr)
{
	size_t len = 0;
	ssize_t read = 1;
	char delim[] = " \n\t";
	char *fraginputstr[1000];
	int i = 0, y = 0;

	while (1)
	{
		printf("($) ");
		read = getline(&inputstr, &len, stdin);
		if (read != -1)
		{
			y = 0;
			fraginputstr[y] = strtok(inputstr, delim);
			while (fraginputstr[y] != NULL)
			{
				y++;
				fraginputstr[y] = strtok(NULL, delim);
			}
		}
		else /* Check for custom EOF i.e Crtl+D */
		{
			free(inputstr);
			printf("\n");
			exit(0);
		}

		if (strcmp(fraginputstr[0], "exit") == 0)
		{
			exit(0);
		}

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

		free(inputstr);
		exit(0);
	}
	else
		wait(NULL);

	return (0);
}
