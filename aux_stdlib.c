#include "main.h"

/**
 * get_len - Determine how long a number is.
 * @n: Integer.
 *
 * Return: How long a number is.
 */


int get_len(int n)
{
	unsigned int n1;
	int length = 1;

	if (n < 0)
	{
		length++;
		n1 = (unsigned int)(-n);
	}
	else
	{
		n1 = (unsigned int)n;
	}
	while (n1 > 9)
	{
		length++;
		n1 /= 10;
	}

	return (length);
}


/**
 * aux_itoa - Transform an integer to a string.
 * @n: integer.
 *
 * Return: String.
 */


char *aux_itoa(int n)
{
	unsigned int n1;
	int length = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));
	if (buffer == NULL)
		return (NULL);

	buffer[length] = '\0';

	if (n < 0)
	{
		n1 = (unsigned int)(-n);
		buffer[0] = '-';
	}
	else
	{
		n1 = (unsigned int)n;
	}

	length--;
	do {
		buffer[length] = (n1 % 10) + '0';
		n1 /= 10;
		length--;
	} while (n1 > 0);

	return (buffer);
}


/**
 * _atoi - Transform string into integer.
 * @s: String.
 *
 * Return: Integer.
 */


int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - '0') * m);
		m /= 10;
	}
	return (oi * pn);
}
