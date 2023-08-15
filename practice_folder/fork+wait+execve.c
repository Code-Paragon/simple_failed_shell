#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * main -  executes the command ls -l /tmp in 5 different child processes
 *
 * Return: 0
 */
int main(void)
{
	int num_children = 5, i;
	pid_t child_pid, wait_pid;
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < num_children; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork Error");
			exit(-1);
		}
		else if (child_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("failed execve");
		}
		else
		{
			wait_pid = wait(NULL);
			printf("This is Child (%d) shonen!\n", wait_pid);
		}
	}
	printf("All recruits ready Sir!\n");
	return (0);
}
