#include "main.h"

/**
 * _strcat - Joins two strings.
 * @dest: Final destination string pointer.
 * @src: Origin of string pointer.
 *
 * Return: Pointer to the destination string.
 */


char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}


/**
 * _strcpy - Facsimile string from origin to final destination.
 * @dest: Final destination of  string pointer.
 * @src: Origin of string pointer.
 *
 * Return: Pointer to the destination string.
 */


char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}


/**
 * _strcmp - Juxtapose a pair of strings.
 * @s1: String One (1).
 * @s2: String Two (2).
 *
 * Return: 0 if strings are equal, 1 if s1 > s2, -1 if s1 < s2.
 */


int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _strchr - Pinpoint single character.
 * @s: Source string.
 * @c: Found char.
 *
 * Return: Pointer to the first occurrence of 'c' in 's', or NULL if not found.
 */


char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}


/**
 * _strspn - How long a prefix substring is.
 * @s: Source string.
 * @accept: The set of characters to match in 's'.
 *
 * Return: The number of bytes in the initial segment of 's' consisting
 * of only the characters from 'accept'.
 */


int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
