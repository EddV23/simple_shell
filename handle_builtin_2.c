#include "shell.h"
/**
 * child_proc - creates a sub process
 * @cmd: pointer to tokenized command
 * @n: pointer to the name of shell
 * @c: count of executions
 * @ev: pointer to the environmental variables
 *
 * Return: 0 for success, -1 if NULL
 */
int child_proc(char *cmd[], char *n, int c, char *ev[])
{
	pid_t pid;
	int stt;

	if (*cmd == NULL)
	{
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if ((_strncmp(*cmd, "./", 2) != 0) && (_strncmp(*cmd, "/", 1) != 0))
			ev_path(cmd);
		if (execve(*cmd, cmd, environ) == -1)
		{
			error_msg(cmd[0], c, ev);
			free(n);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&stt);
	return (0);
}

/**
 * builtin_hd - this handles the builtin commands
 * @cmd: pointer to tokenized command
 * @exstat: exit status
 *
 * Return: 0 for success, -1 for failure
 */

int builtin_hd(char **cmd, int exstat)
{
	cmd_blt cmb[] = {
		{"echo", my_echo},
		{"env", print_ev},
		{"help", _help},
		{"cd", cwd},
		{"history", print_hist},
		{NULL, NULL}
	};
	int idx = 0;

	while ((cmb + idx)->tok)
	{
		if (_strcmp(cmd[0], (cmb + idx)->tok) == 0)
			return ((cmb + idx)->myexec(cmd, exstat));
		idx++;
	}
	return (-1);
}

/**
 * builtin_ch - this checks the builtin commands
 * @cmd: pointer to tokenized command
 *
 * Return: 0 for success, -1 for failure
 */
int builtin_ch(char **cmd)
{
	cmd_blt myexec[] = {
		{"echo", NULL},
		{"env", NULL},
		{"help", NULL},
		{"cd", NULL},
		{NULL, NULL}
	};
	int idx = 0;

	if (*cmd == NULL)
		return (-1);
	while ((myexec + idx)->tok)
	{
		if (_strcmp(cmd[0], (myexec + idx)->tok) == 0)
			return (0);
		idx++;
	}
	return (-1);
}

/**
 * ev_crt - produces an array of enviroment variables
 * @ev: pointer to the enviroment variable
 *
 * Return: void
 */
void ev_crt(char *ev[])
{
	int i = 0;

	while (environ[i])
	{
		ev[i] = _strdup(environ[i]);
		i++;
	}
	ev[i] = NULL;
}
