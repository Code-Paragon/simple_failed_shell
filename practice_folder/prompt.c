#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints "$ " then scans user input and prints it
 *
 * Return: 0
 */
int main(void)
{
	char *buff = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&buff, &len, stdin);
	if (read != -1)
	{
		printf("Read %zd characters: %s", read, buff);
	}
	else
		perror("getline");
	free(buff);

	return (0);
}
