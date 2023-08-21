#include <stdlib.h>
/**
 * _realloc -  function that reallocates a memory block using malloc and free
 * @ptr: pointer
 * @old_size: int
 * @new_size: int
 *
 * Return: void
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *ptrt;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptrt = malloc(new_size);
	if (ptrt == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
	{
		ptrt[i] = ((char *)ptr)[i];
	}
	free(ptr);
	return (ptrt);
}
