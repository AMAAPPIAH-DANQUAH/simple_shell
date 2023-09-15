#include "main.h"


/**
 * _memcpy - Copy data between memory locations.
 * @newptr: Destination memory location.
 * @ptr: Source memory location.
 * @size: Number of bytes to copy.
 *
 * Return: No return value.
 */


void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_newptr = (char *)newptr;
	char *char_ptr = (char *)ptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}


/**
 * _realloc - Allot memory for a pointer.
 * @ptr: Pointer to the hitherto alloted memory.
 * @old_size: Size of the old memory block in bytes.
 * @new_size: Size of the new memory block in bytes.
 *
 * Return: Pointer to the newly allocated memory block.
 *         Returns NULL on failure.
 */


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}


/**
 * _reallocdp - Reallocate memory for a double pointer.
 * @ptr: Pointer to a double-pointed memory allocation.
 * @old_size: Size of the old memory block in bytes.
 * @new_size: Size of the new memory block in bytes.
 *
 * Return: Pointer to the newly allocated memory block.
 *         Returns NULL on failure.
 */


char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);
	return (newptr);
}

