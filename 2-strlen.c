/**
 * _strlen -  function that returns the length of a string.
 * @s: string pointer
 *
 * Return: the length of string
 */
int _strlen(char *s)
{
	int i = 0, m = 0;

	while (s[i] != '\0')
	{
		m++;
		i++;
	}
	return (m);
}
