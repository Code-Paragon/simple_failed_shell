#include "main.h"

/**
 * main - a simple shell
 *
 * Return: 0
 */

int main(void)
{
	char *inputstr = NULL, *const envp[] = {NULL};
	int shelly = shell(envp, inputstr);

	if (shelly == 1)
		perror("ERROR");

	return (0);
}
