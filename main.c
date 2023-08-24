#include "main.h"

/**
 * main - a simple shell
 * @argc: argument count
 * @args: argument vector
 * @front: pointer to fist argument
 *
 * Return: 0
 */

int main(int __attribute__((__unused__)) argc, char **args, char **front)
{
	char *inputstr = NULL, *const envp[] = {NULL};
	int shelly = shell(envp, inputstr, args, front);

	if (shelly == 1)
		perror("ERROR");

	return (0);
}
