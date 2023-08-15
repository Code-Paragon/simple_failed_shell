#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
/**
 * main - looks for files in the current PATH
 *
 * Return: 0
 */
int main (int ac, char ** av)
{
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("_which filename ...\n");
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s: ", av[i]);
		if (stat(av[i], &st) == 0)
			printf("File Found!\n");
		else
			printf("File Not Found\n");
		i++;
	}
	return (0);
}
