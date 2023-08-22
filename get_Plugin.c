#include "main.h"
/**
 * get_Plugin - Matches a command with a corresponding shellby builtin function
 * @command: The command to match.
 *
 * Return: A function pointer to the corresponding Plugin.
 */
int (*get_Plugin(char *command))(char **args, char **front)
{
	Plugin_t functions[] = {
		{ "env", com_env },
		{ "setenv", com_setenv },
		{ "unsetenv", com_unsetenv },
		{ "cd", com_cd },
		{ NULL, NULL }
	};
	int h;
	for (h = 0; functions[h].comName; i++)
	{
		if (_strcmp(functions[h].comName, command) == 0)
			break;
	}
	return (functions[h].comFunc);
}
