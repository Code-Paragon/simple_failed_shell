#include "main.h"

int shell_exit(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL && isdigit(*args[1]))
	{
		exit_status = _atoi(args[1]);
	}
	/* exit with 0 if no exit status is passed */
	
	exit(exit_status);
}
