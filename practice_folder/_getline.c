#include "main.h"
/**
 * main - prints "$ " then scans user input and prints it
 *
 * Return: 0
 */
int _getline(char *buffer)
{
	int Bytesread;

	Bytesread = read(STDIN_FILENO, buffer, sizeof(buffer));
	if (Bytesread != -1)
	{
		perror("_getline read failed");
		return (-1);
	}
	return (0);
}
