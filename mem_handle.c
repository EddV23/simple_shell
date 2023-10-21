#include "shell.h"

/**
 * mem_calloc -  uses malloc to allcoate memory to an array
 * @s: the size of bytes to allocate
 *
 * Return: void
 */
void *mem_calloc(unsigned int s)
{
	unsigned int i = 0;
	char *bytes;

	if (s == 0)
		return (NULL);
	bytes = malloc(s);
	if (bytes == NULL)
		return (NULL);
	while (i < s)
	{
		bytes[i] = '\0';
		i++;
	}
	return (bytes);
}

/**
 * mem_copy - copy bytes from a source to a destination
 * @dest: destination
 * @src: source
 * @n: delimeter
 *
 * Return: void
 */
char *mem_copy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * mem_clear - clear memory allocated to pointer
 * @cmd: the pointer to the tokenized command
 * @buf: the file's line
 *
 * Return: void
 */
void mem_clear(char *cmd[], char *buf)
{
	free(cmd);
	free(buf);
	cmd = NULL;
	buf = NULL;
}

/**
 * alloc_delim - use a delim or constant when filling an array
 * @bytes: the bytes allocated
 * @n: constant byte
 * @s: the size of bytes to allocate
 *
 * Return: void
 */
void *alloc_delim(void *bytes, int n, unsigned int s)
{
	unsigned int i = 0;
	char *p = bytes;

	while (i < s)
	{
		*p = n;
		p++;
		i++;
	}
	return (bytes);
}

/**
 *mem_realloc - uses malloc to reallcoate and free memory for a pointer
 *@buf: the bytes allocated
 *@s1: initial pointer size
 *@s2: new pointer size
 *
 *Return: void
 */
void *mem_realloc(void *buf, unsigned int s1, unsigned int s2)
{
	void *bytes;

	if (s2 == s1)
		return (buf);
	if (s2 == 0 && buf)
	{
		free(buf);
		return (NULL);
	}
	bytes = malloc(s2);
	if (bytes == NULL)
		return (NULL);
	if (buf == NULL)
	{
		alloc_delim(bytes, '\0', s2);
		free(buf);
	}
	else
	{
		mem_copy(bytes, buf, s1);
		free(buf);
	}
	return (bytes);
}
