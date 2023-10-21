#include "shell.h"

/**
 * pr_error - prints an error message
 * @av: pointer to the name of the shell
 * @c: count of executions
 * @cmd: pointer to tokenized command
 *
 * Return: void
 */
void pr_error(char *av[], int c, char *cmd[])
{
	char *exstat = _itoa(c);

	_printf(av[0]);
	_printf(": ");
	_printf(exstat);
	_printf(": ");
	_printf(cmd[0]);
	_printf(": Invalid input: ");
	_printf(cmd[1]);
	_printf("\n");
	free(exstat);
	/*print("%s: %d: %s: Invalid input: %s\n", av[0], c, cmd[0], cmd[1]);*/
}

/**
 * print_hist - prints the user's command history
 * @cmd: the pointer to the tokenized command
 * @stt: the exit status
 * Return: 0 Succes -1 Fail
 */
int print_hist(char **cmd, int stt)
{
	char *name = ".my_history", *buf = NULL, *exstat;
	FILE *myfile;
	size_t size = 0;
	int i = 0;

	(void)cmd;
	(void)stt;

	myfile = fopen(name, "r");
	if (myfile == NULL)
		return (-1);
	while ((getline(&buf, &size, myfile)) != -1)
	{
		i++;
		exstat = _itoa(i);
		_printf(exstat);
		free(exstat);
		_printf(" ");
		_printf(buf);

	}
	if (buf)
		free(buf);
	fclose(myfile);
	return (0);
}
/**
 * echo_disp - utilize the command echo
 * @cmd: pointer to the tokenized command
 *
 * Return: Always 0 (Success)
 */
int echo_disp(char **cmd)
{
	pid_t pid;
	int stt;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
			return (-1);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &stt, WUNTRACED);
		} while (!WIFEXITED(stt) && !WIFSIGNALED(stt));
	}
	return (1);
}

/**
 * _abs - prints an integer
 * @n: integer to be printed
 *
 * Return: void
 */
void _abs(int n)
{
	unsigned int u = n;

	if (n < 0)
	{
		_putchar('-');
		u = -u;
	}
	if ((u / 10) > 0)
		_num(u / 10);

	_putchar(u % 10 + '0');
}

/**
 * _num - print an unsigned integer
 * @n: the unisigned integer to be printed
 *
 * Return: void
 */
void _num(unsigned int n)
{
	unsigned int u = n;

	if ((u / 10) > 0)
		_num(u / 10);

	_putchar(u % 10 + '0');
}
