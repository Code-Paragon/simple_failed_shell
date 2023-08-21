#include "main.h"

/**
 * _strtok - tokenizes the string passed
 *
 * @str: string passed in to be tokenised
 * @delim: delimeter character that separates tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_token_end;
	char *token_start, *token;
	int i, token_length;

	/* if str is NULL assign last_token_end to string */
	if (str == NULL)
		str = last_token_end;
	/* returns NULL if an argument is mising in function */
	if (str == NULL && delim == NULL)
	{
		return (NULL);
	}
	/* str points to start of the current token */
	while (*str != '\0' && strchr(delim, *str) != NULL)
		str++;
	if (*str == '\0')
		return (NULL);

	token_start = str;

	/* str points to the end of the last token */
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
		/* assigns the token end to last_token_end */
		last_token_end = str;
	}
	return (token);
}
