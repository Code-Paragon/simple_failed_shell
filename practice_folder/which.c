#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av, char **env) {
	char *path;
	char *token;
	char *delim = ":";

	path = getenv("PATH");

	printf("%s\n", path);

	token = strtok(path, delim);

	printf("%s", token);


	return (0);
}