#include <stdio.h>
#include <unistd.h>
/**
 * main - prints ppid
 *
 * Return: 0
 */
int main(void)
{
	pid_t myParentPid = getppid();
	printf("The parent process ID is: %u\n", myParentPid);

	return (0);
}
