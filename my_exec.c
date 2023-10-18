#include "shell.h"

/**
 * display_ev - prints environmental variables
 * @ev: pointer to the environmental variables
 *
 * Return: void
 */
void display_ev(char *ev[])
{
	size_t i = 0, length = 0;

	for (i = 0, length = 0; ev[i]; i++)
	{
		length = _strlen(ev[i]);
		write(STDOUT_FILENO, ev[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * error_msg - displays an error message
 * @n: name of the shell
 * @c: counts of executions
 * @cmd: pointer to tokenized command
 *
 * Return: void
 */
void error_msg(char *n, int c, char **cmd)
{
	char counts;

	counts = c + '0';
	write(STDOUT_FILENO, n, _strlen(n));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &counts, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, cmd[0], _strlen(cmd[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 * ev_path - obtains the full value of the path of an environmental variable
 * @ev: pointer to the environmental variables
 *
 * Return: paths for the commands that are tokenized
 */
char **ev_path(char *ev[])
{
	unsigned int i = 0;
	char **paths = NULL, *val = NULL;

	val = strtok(ev[i], "=");
	for (i = 0; ev[i]; i++)
	{
		if (_strcmp(val, "PATH"))
		{
			val = strtok(NULL, "\n");
			paths = create_str_cmd(val, ":");
			return (paths);
		}
		val = strtok(ev[i], "=");
	}
	return (NULL);
}

/**
 * exec - executes a command
 * @cmd: pointer to tokenized command
 * @n: pointer to name of the shell
 * @ev: pointer to the environmental variables
 * @c: count of executions
 *
 * Return: void
 */
void exec(char *cmd[], char *n, char *ev[], int c)
{
	unsigned int i;
	struct stat st;
	char **paths = NULL, *abs_path = NULL;

	if (_strcmp(cmd[0], "ev") != 0)
		display_ev(ev);
	if (stat(cmd[0], &st) == 0)
	{
		if (execve(cmd[0], cmd, ev) < 0)
		{
			perror(n);
			free_cmd_ex(cmd);
		}
	}
	else
	{
		paths = ev_path(ev);
		while (paths[i])
		{
			abs_path = _strcat(paths[i], cmd[0]);
			i++;
			if (stat(abs_path, &st) == 0)
			{
				if (execve(abs_path, cmd, ev) < 0)
				{
					perror(n);
					free_cmd_mem(paths);
					free_cmd_ex(cmd);
				}
				return;
			}
		}
		error_msg(n, c, cmd);
		free_cmd_mem(paths);
	}
}
