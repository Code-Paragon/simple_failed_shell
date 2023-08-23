#include "main.h"
void assign_inputstr(char **inputstr, size_t *mi, char *buff, size_t bi);

/**
 * assign_inputstr - Reassigns the inputstr variable for _getline.
 * @inputstr: A buffer to store an input string.
 * @mi: The size of inputstr.
 * @buff: The string to assign to inputstr.
 * @bi: The size of buffer.
 *
 * Return: void
 */
void assign_inputstr(char **inputstr, size_t *mi, char *buff, size_t bi)
{
	if (*inputstr == NULL)
	{
		if (bi > 120)
			*mi = bi;
		else
			*mi = 120;
		*inputstr = buff;
	}
	else if (*mi < bi)
	{
		if (bi > 120)
			*mi = bi;
		else
			*mi = 120;
		*inputstr = buff;
	}
	else
	{
		_strcpy(*inputstr, buff);
		free(buff);
	}
}
/**
 * _getline - Reads input from a stream.
 * @inputstr: A buffer to store the input.
 * @m: The size of inputstr.
 * @dstream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **inputstr, size_t *m, FILE *dstream)
{
	static ssize_t inputed;
	ssize_t reti;
	char cx = 'x', *buf;
	int ri;

	if (inputed == 0)
		fflush(dstream);
	else
		return (-1);
	inputed = 0;

	buf = malloc(sizeof(char) * 120);
	if (!buf)
		return (-1);
	while (cx != '\n')
	{
		ri = read(STDIN_FILENO, &cx, 1);

		if (ri == -1 || (ri == 0 && inputed == 0))
		{
			free(buf);
			return (-1);
		}

		if (ri == 0 && inputed != 0)
		{
			inputed++;
			break;
		}
		if (inputed >= 120)
			buf = _realloc(buf, inputed, inputed + 1);
		buf[inputed] = cx;
		inputed++;
	}
	buf[inputed] = '\0';

	assign_inputstr(inputstr, m, buf, inputed);

	reti = inputed;
	if (ri != 0)
		inputed = 0;
	return (reti);
}
