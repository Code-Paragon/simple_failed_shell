/**
 * _strcat - function that concatenates two strings.
 * @dest: string
 * @src: string
 *
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, m = 0, k;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[m] != '\0')
	{
		m++;
	}
	for (k = 0; k <= m; k++)
	{
		dest[i] = src[k];
		i++;
	}
	return (dest);
}
