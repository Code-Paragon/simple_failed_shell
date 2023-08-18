/**
 * _strcpy - a function that copies str src to dest
 * @dest: a buffer ptr
 * @src: string copied
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, p;

	while (src[i] != '\0')
	{
		i++;
	}
	for (p = 0; p <= i; p++)
	{
		dest[p] = src[p];
	}
	return (dest);
}
