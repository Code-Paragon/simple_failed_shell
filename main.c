#include "main.h"

/**
 * main - a simple shell
 *
 * Return: 0
 */

int main(void)
{
	char *inputstr = NULL;
	int shelly = shell(inputstr);
	if (shelly == 1)
		perror("ERROR");

	return (0);
}
