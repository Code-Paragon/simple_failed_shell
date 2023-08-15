#include "main.h"

/**
 * main - a simple shell
 *
 * Return: 0
 */

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
