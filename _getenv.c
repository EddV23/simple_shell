#include "shell.h"

/**
 * _getenv - obtain the environmental variable's value
 * @n: the name of this environmental value
 *
 * Return: value of environmental variable
 */
char *_getenv(char *n)
{
	size_t size, bytes;
	char *val;
	int i = 0, ev = 0, c;

	size = _strlen(n);
	while (environ[i])
	{
		if (_strncmp(n, environ[i], size) == 0)
		{
			bytes = _strlen(environ[i]) - size;
			val = malloc(sizeof(char) * bytes);
			if (!bytes)
			{
				free(val);
				perror("Memory allocation failed");
				return (NULL);
			}
			for (c = size + 1; environ[i][c]; c++, ev++)
				val[ev] = environ[i][c];
			val[ev] = '\0';
			return (val);
		}
		i++;
	}
	return (NULL);
}

/**
 * ev_path - find command in $PATH
 * @cmd: pointer to the tokenized command
 *
 * Return: 0 for Success, 1 for failure
 */
int ev_path(char *cmd[])
{
	char *paths, *val, *abs_path;
	struct stat st;

	paths = _getenv("PATH");
	val = _strtok(paths, ":");
	while (val != NULL)
	{
		abs_path = exec(*cmd, val);
		if (stat(abs_path, &st) == 0)
		{
			*cmd = _strdup(abs_path);
			free(abs_path);
			free(paths);
			return (0);
		}
		free(abs_path);
		val = _strtok(NULL, ":");
	}
	free(paths);
	return (1);
}

/**
 * ev_clear - clear the memory of enviroment variables
 * @ev: pointer to the environmental variables
 *
 * Return: void
 */
void ev_clear(char *ev[])
{
	int i = 0;

	while (ev[i])
	{
		free(ev[i]);
		i++;
	}
}

/**
 * exec - executes a command
 * @cmd: the tokenized command
 * @loc: location or path of the tokenized command
 *
 * Return: path of the command
 */
char *exec(char *cmd, char *loc)
{
	size_t size;
	char *tok;

	if (cmd == NULL || loc == NULL)
	{
		return (NULL);
	}
	size = _strlen(loc) + _strlen(cmd) + 2;
	tok = malloc(sizeof(char) * (size));
	if (tok == NULL)
	{
		return (NULL);
	}
	memset(tok, 0, size);

	_strcat(tok, loc);
	_strcat(tok, "/");
	_strcat(tok, cmd);

	return (tok);
}
