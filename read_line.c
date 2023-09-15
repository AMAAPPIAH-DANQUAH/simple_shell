#include "main.h"

/**
 * read_line - Receives inputed string from standard input
 *
 * @i_eof: Pointer to store the result of the getline function
 *
 * Return: The inputed string received from standard input
 */


char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
