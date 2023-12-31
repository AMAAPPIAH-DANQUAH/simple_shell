#include "main.h"

/**
 * bring_line - Makes sure @lineptr points to a good buffer.
 * @lineptr:  Points to the line buffer.
 * @n: Point to how big buffer is
 * @buffer: string containing line buffer
 * @j: How big/small buffer is
 */


void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if (*lineptr == NULL)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}


/**
 * get_line - Receives an entry from a particular stream of entries.
 * @lineptr: Buffer for storing entry.
 * @n: How big the buffer is.
 * @stream: Source stream
 * Return: Size in bytes, received from source stream.
 */


ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);

	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	bring_line(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
