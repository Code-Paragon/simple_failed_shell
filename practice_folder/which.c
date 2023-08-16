#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av, char **env) {
	char *path;

	path = getenv("PATH");

	printf("%s\n", path);


	return (0);
}