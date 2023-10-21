#include "shell.h"

/**
 * clear_stdin_buffer - clears the standard input buffer
 *
 * Return: void
 */
void clear_stdin_buffer(void)
{
	fflush(stdin);
}

/**
 * hd_hash - handle contents after hash
 * @n: the input buffer
 *
 * Return:void
 */
void hd_hash(char *n)
{
	int i = 0;

	while (n[i] != '\0')
	{
		if (n[i] == '#')
		{
			n[i] = '\0';
			break;
		}
		i++;
	}
}

/**
 * _getline - reads an entire line from a standard input
 *
 * Return: character
 */
char *_getline(void)
{
	int i, size = BUFFER_SIZE, len;
	char *buf = malloc(size), c = 0;

	if (buf == NULL)
	{
		free(buf);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		clear_stdin_buffer();
		len = read(STDIN_FILENO, &c, 1);
		if (len == 0)
		{
			free(buf);
			exit(EXIT_SUCCESS);
		}
		buf[i] = c;
		if (buf[0] == '\n')
		{
			free(buf);
			return ("\0");
		}
		if (i >= size)
		{
			buf = mem_realloc(buf, size, size + 1);
			if (buf == NULL)
				return (NULL);
		}
	}
	buf[i] = '\0';
	hd_hash(buf);
	return (buf);
}

/**
 * signal_handler - handles the interupt signal
 * @s: signal to be handled
 *
 * Return: void
 */
void signal_handler(int s)
{
	if (s == SIGINT)
		_printf("\n#cisfun$ ");
}
