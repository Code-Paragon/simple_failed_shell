#include <stdio.h>
/**
 * main - prints the members of av
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	int i, l = 0;

	while (av[l])
	{
		l++;
	}
	for (i = 0; i < l; i++)
	{
		printf("av[%u]: %s\n", i, av[i]);
	}

	return (0);
}
