#include <stdio.h>

extern char **environ;

int _printenv(void)
{
    /* Loop through the environment variables and print them */
    for (char **env = environ; *env != NULL; env++) 
    {
        printf("%s\n", *env);
    }

    return 0;
}
