#include "main.h"

char execute (char *fraginputstr, char *envp)
{
	char *cmd;
	char *command = fraginputstr;


	if (command[0] != "/")
		command = handle_path(fraginputstr[0]);
	
	else
		execve(fraginputstr[0], fraginputstr, envp);

	return NULL;
}