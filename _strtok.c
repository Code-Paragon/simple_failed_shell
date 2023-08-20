#include "main.h"

char *_strtok(char *str, const char *delim)
{
	static char *last_token_end = NULL;
	char *token_start, *token;
	int i, token_length;

	if (str == NULL)
		str = last_token_end;

	if (str == NULL && delim == NULL)
	{
		return (NULL);
	}

	while (*str != '\0' && strchr(delim, *str) != NULL)
		str++;

	if (*str == '\0')
		return (NULL);

	token_start = str;

	while (*str != '\0' && strchr(delim, *str) == NULL)
		str++;

	token_length = str - token_start;
	token = malloc(token_length + 1);

	if (token != NULL)
	{
		for (i = 0; i < token_length; i++)
		{
			token[i] = token_start[i];
		}
		token[token_length] = '\0';
		last_token_end = str;
	}
	return token;
}
