#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _strchr -  function locates a char in a str
 * @s: str
 * @c: char
 *
 * Return: ptr
 */
char *_strchr(char *s, char c)
{
	int i = 0, m = 0;
	char *e, y = '0';

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			e = &s[i];
			m++;
			break;
		}
		i++;
	}
	if (m != 0)
	{
		return (e);
	}
	else
	{
		e = &y;
		return (e);
	}
}
