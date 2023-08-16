#include "main.h"

int execute(char *fraginputstr[], char *envp[])
{
	char *command = fraginputstr[0];
	char *fullpath;


	if (command[0] != '/'){
		fullpath = handle_path(command);
	
		if (fullpath != NULL)
		{
				execve(fullpath, fraginputstr, envp);
				perror("execve");
		}
    } else {
        execve(command, fraginputstr, envp);
        perror("execve");
    }

    return -1;
}
