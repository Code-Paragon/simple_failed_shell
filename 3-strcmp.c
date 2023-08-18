/**
 * _strcmp - function that compares two strings.
 * @s1: string
 * @s2: string
 *
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, l, m, d, k = 0, q = 0;

	while (s1[k] != '\0')
	{
		k++;
	}
	while (s2[q] != '\0')
	{
		q++;
	}
	while ((s1[i] != '\0') && (s2[i] != '\0'))
	{
		l = s1[i];
		m = s2[i];
		if (l == m)
		{
			d++;
			i++;
			continue;
		}
		else
		{
			if (l < m)
			{
				return (-13);
				break;
			}
			else
			{
				return (13);
				break;
			}
		}
	}
	if ((d == k) || (d == q))
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}
