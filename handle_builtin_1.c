#include "shell.h"

/**
 * my_echo - enables the use of the command echo
 * @cmd: pointer to the tokenized command
 * @exstat: exit status
 *
 * Return: Always 0 (Success)
 */
int my_echo(char *cmd[], int exstat)
{
	unsigned int  pid = getppid();
	char *paths;

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		_abs(exstat);
		_printf("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		_num(pid);
		_printf("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		paths = _getenv("PATH");
		_printf(paths);
		_printf("\n");
		free(paths);
	}
	else
		return (echo_disp(cmd));
	return (1);
}

/**
 * print_ev - prints environmental variables
 * @cmd: pointer to the tokenized command
 * @exstat: exit status
 *
 * Return: Always 0 (Success)
 */
int print_ev(char *cmd[], int exstat)
{
	size_t i = 0, length;

	(void)cmd;
	(void)exstat;

	for (i = 0; environ[i] != NULL; i++)
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * _help - prints help info for builtin commands
 * @cmd: pointer to the tokenized command
 * @exstat: exit status
 *
 * Return: Always 0 (Success)
 */
int _help(char *cmd[], int exstat)
{
	int fd, read_check, write_check;
	char s;

	(void)exstat;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	read_check = 1;
	while (read_check > 0)
	{
		read_check = read(fd, &s, 1);
		write_check = write(STDOUT_FILENO, &s, read_check);
		if (write_check < 0)
			return (-1);
	}
	_putchar('\n');
	return (0);
}

/**
 * cwd - handles the 'cd' command and its variations
 * @cmd: pointer to the tokenized command
 * @exstat: exit status
 *
 * Return: Always 0 (Success)
 */
int cwd(char **cmd, int exstat)
{
	int val = -1;
	char cur_dir[PATH_MAX];

	(void)exstat;

	if (_strcmp(cmd[1], "-") == 0)
		val = chdir(getenv("OLDPWD"));
	else if (cmd[1] == NULL)
		val = chdir(getenv("HOME"));
	else
		val = chdir(cmd[1]);

	if (val != -1)
	{
		getcwd(cur_dir, sizeof(cur_dir));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cur_dir, 1);
	}
	else if (val == -1)
	{
		perror("Error");
		return (-1);
	}
	return (0);
}

/**
 * quit_shell - quits or exits the shell
 * @cmd: pointer to tokenized command
 * @n: pointer to the name of shell
 * @ev: pointer to the environmental variables
 * @c: count of executions
 *
 * Return: void
 */
void quit_shell(char *cmd[], char *n, char *ev[], int c)
{
	int stt, i = 0;

	if (cmd[1] == NULL)
	{
		free(n);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			pr_error(ev, c, cmd);
			break;
		}
		else
		{
			stt = _atoi(cmd[1]);
			free(n);
			free(cmd);
			exit(stt);
		}
	}
}
