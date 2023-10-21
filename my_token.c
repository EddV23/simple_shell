#include "shell.h"

/**
 * cmd_prompt - prints the command line prompt
 *
 * Return: void
 */
void cmd_prompt(void)
{
	_printf("#cisfun$ ");
}

/**
 * _strtok - splits and create a full string command
 * @str: pointer to input string
 * @bytes: delimeter for the strtok function
 *
 * Return: a full string command
 */
char *_strtok(char *str, const char *bytes)
{
	unsigned int i = 0;
	static char *cmd, *buf;

	if (str != NULL)
		buf = str;
	cmd = buf;
	if (cmd == NULL)
		return (NULL);
	while (cmd[i] != '\0')
	{
		if (is_delim(cmd[i], bytes) == 0)
			break;
		i++;
	}
	if (buf[i] == '\0' || buf[i] == '#')
	{
		buf = NULL;
		return (NULL);
	}
	cmd = buf + i;
	buf = cmd;
	while (buf[i] != '\0')
	{
		if (is_delim(buf[i], bytes) == 1)
			break;
		i++;
	}
	if (buf[i] == '\0')
		buf = NULL;
	else
	{
		buf[i] = '\0';
		buf = buf + i + 1;
		if (*buf == '\0')
			buf = NULL;
	}
	return (cmd);
}

/**
 * is_delim - evaluates if a character in a
 *            string is a delimiter
 * @s: character
 * @str: string
 *
 * Return: Always 0 (Success)
 */
unsigned int is_delim(char s, const char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
	{
		if (s == str[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * crt_token - creates tokens from user input
 * @n: the input string to be tokenized
 *
 * Return: tokens
 */
char **crt_token(char *n)
{
	char **buf, *c;
	int i, size = BUFFER_SIZE;

	if (n == NULL)
		return (NULL);
	buf = malloc(sizeof(char *) * size);
	if (!buf)
	{
		perror("hsh");
		return (NULL);
	}
	c = _strtok(n, "\n ");
	for (i = 0; c; i++)
	{
		buf[i] = c;
		c = _strtok(NULL, "\n ");
	}
	buf[i] = NULL;
	return (buf);
}

/**
 * error_msg - displays an error message
 * @n: the input string
 * @c: counts of executions
 * @cmd: pointer to tokenized command
 *
 * Return: void
 */
void error_msg(char *n, int c, char *cmd[])
{
	char *exstat;

	_printf(cmd[0]);
	_printf(": ");
	exstat = _itoa(c);
	_printf(exstat);
	free(exstat);
	_printf(": ");
	_printf(n);
	_printf(": not found\n");
}
