#include "shell.h"

/**
 * handle_builtin - handles the builtin commands
 * @cmd: array of command tokens
 * @prev_dir: pointer to the previous directory
 * @home: pointer to the home directory
 *
 * Return: 0 on success, -1 on failure or exit
 */
int handle_builtin(char **cmd, char **prev_dir, char *home)
{
	if (_strcmp(cmd[0], "exit") == 0)
		return (-1);
	/*else if (_strcmp(cmd[0], "env") == 0)*/
	/*	display_ev();*/
	else if (_strcmp(cmd[0], "setenv") == 0)
	{
		if (cmd[1] && cmd[2])
			sh_setenv(cmd[1], cmd[2], 1);
		else
			fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
	}
	else if (_strcmp(cmd[0], "unsetenv") == 0)
	{
		if (cmd[1])
			sh_unsetenv(cmd[1]);
		else
			fprintf(stderr, "Usage: unsetenv VARIABLE\n");
	}
	else if (_strcmp(cmd[0], "cd") == 0)
	{
		if (cmd[1] == NULL || _strcmp(cmd[1], "~") == 0)
			cwd(home, prev_dir, home);
		else if (_strcmp(cmd[1], "-") == 0)
			cwd(*prev_dir, prev_dir, home);
		else
			cwd(cmd[1], prev_dir, home);
	}

	return (0);
}
