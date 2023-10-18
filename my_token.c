#include "shell.h"

/**
 * create_str_cmd - splits and create a full string command
 * @buf: pointer to input string
 * @str: delimeter for the strtok function
 *
 * Return: a full string command
 */
char **create_str_cmd(char *buf, const char *str)
{
	int i = 0;
	size_t bytes = 0;
	char *tok = NULL, **cmd = NULL;

	bytes = _strlen(buf);
	cmd = malloc((bytes + 1) * sizeof(char *));
	if (cmd == NULL)
	{
		perror("Cannot alloxate buffer");
		free(buf);
		free_cmd_mem(cmd);
		exit(EXIT_FAILURE);
	}

	if (buf == NULL)
		return (NULL);

	tok = strtok(buf, str);
	while (tok != NULL)
	{
		cmd[i] = malloc(_strlen(tok) + 1);
		if (cmd[i] == NULL)
		{
			perror("Cannot allocate buffer");
			free_cmd_mem(cmd);
			return (NULL);
		}
		_strcpy(cmd[i], tok);
		tok = strtok(NULL, str);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
