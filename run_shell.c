#include "shell.h"

/**
 * cmd_prompt - prints the command line prompt
 *
 * Return: void
 */
void cmd_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * signal_handler - handles the interrupt signal
 * @s: the signal to be handled
 *
 * Return: void
 */
void signal_handler(int __attribute__((__unused__)) s)
{
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

/**
 * quit_shell - quits or exits the shell
 * @cmd: pointer to tokenized command
 *
 * Return: void
 */
void quit_shell(char **cmd)
{
	int stt = 0;

	if (cmd[1] == NULL)
	{
		free_cmd_mem(cmd);
		exit(EXIT_SUCCESS);
	}

	stt = _atoi(cmd[1]);
	free_cmd_mem(cmd);
	exit(stt);
}

/**
 * end_of_file - evaluates if the buffer is at the EOF
 * @buf: pointer to input string
 *
 * Return: void
 */
void end_of_file(char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	/*free(buf);*/
	exit(EXIT_SUCCESS);
}
