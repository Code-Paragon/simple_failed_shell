#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * main - a simple shell
 *
 * Return: 0
 */
int shel(char *, char *const [], size_t, ssize_t, char[], char *[], int, int, int, pid_t);
int main(void)
{
	char *inputstr = NULL, *const envp[] = {NULL};
	size_t len = 0;
	ssize_t read = 1;
	char delim[] = " \n\t";
	char *fraginputstr[1000];
	int inputNum = 1000, i = 0, y = 0;
	pid_t my_pid = 1;
	int shelly = shel(inputstr, envp, len, read, delim, fraginputstr,
			inputNum, i, y, my_pid);
	if (shelly == 1)
		perror("ERROR");

	return (0);
}
/**
 * shel - the main shell
 * @inputstr: usr input
 * @envp: process environ
 * @len: lenght
 * @read: read
 * @delim: delimiters
 * @fraginputstr: seperated input
 * @inputNum: number of inputs
 * @i: loop counter
 * @y: loop counter
 * @my_pid: child pid
 *
 * Return: 1 error, 0 success
 */
int shel(char *inputstr, char *const envp[], size_t len, ssize_t read,
		char delim[], char *fraginputstr[], int inputNum,
		int i, int y, pid_t my_pid)
{
	for (i = 0; i < inputNum; i++)
	{
		my_pid = fork();
		if (my_pid == -1)
		{
			perror("fork failed");
			return (1);
		}
		else if (my_pid == 0)
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
			else/* Check for custom EOF i.e Crtl+D */
			{
				kill(my_pid, SIGTERM);
				free(inputstr);
				printf("\n");
				exit(0);
			}
			if (execve(fraginputstr[0], fraginputstr, envp) == -1)
				perror("./hsh");
			free(inputstr);
			exit(0);
		}
		else
			wait(NULL);
	}
	free(inputstr);
	return (0);
}
