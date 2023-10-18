#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - reads an entire line from a file descriptor
 * @fd: file descriptor
 *
 * Return: the number of characters read or -1 on failure
 */
char *_getline(const int fd)
{
	static char buffer[BUFFER_SIZE];
	static char line[BUFFER_SIZE];
	static size_t pos;
	static size_t len;

	size_t i = 0;
	char c;

	while (1)
	{
		if (pos == len)
		{
			pos = 0;
			len = read(fd, buffer, BUFFER_SIZE);
			if (len == 0)
			{
				if (i == 0)
					return (NULL);
				break;
			}
			if (len == (size_t)-1)
				return (NULL);
		}

		c = buffer[pos++];
		line[i++] = c;
		if (c == '\n')
			break;
	}
	line[i] = '\0';
	return (line);
}
