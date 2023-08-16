#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av, char **env) {
	char *path;
	char *token;
	char *delim = ":";
	char *file;

	path = getenv("PATH");

	token = strtok(path, delim);

	while (token != NULL)
	{
		
		token = strtok(NULL, delim);
		file = strcat(token, "/");
		file = strcat(token, "ls");
		printf("%s\n", token);
	}
	return (0);
}