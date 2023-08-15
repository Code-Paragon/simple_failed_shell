#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * main - a super simple shell
 *
 * Return: 0
 */
int main(void)
{
	char *inputstr = NULL;
	size_t len = 0;
	ssize_t read;
	char delim[] = " \n\t";
	char *fraginputstr[100];
	int y = 0, inputNum = 100, i;
	pid_t my_pid; 

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
			printf("#javis_first$ ");
			read = getline(&inputstr, &len, stdin);
			if (read != -1)
			{
				fraginputstr[y] = strtok(inputstr, delim);
				while (fraginputstr[y] != NULL)
				{
					y++;
					fraginputstr[y] = strtok(NULL, delim);
				}
			}
			else
			{
				free(inputstr);
				perror("getline failed");
				return (1);
			}
			if (execvp(fraginputstr[0], fraginputstr) == -1)
				perror("execve failed");
			free(inputstr);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}
	free(inputstr);
	return (0);
}
