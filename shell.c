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
 * main - Entry point, runs the simple shell
 * @ac: argument count
 * @av: arguments vector
 * @ev: pointer to array of environmental variables
 *
 * Return: Always 0 (Success)
 */
int main(int __attribute__((__unused__)) ac, char *av[], char *ev[])
{
	int i = 0;
	size_t bytes = 0;
	ssize_t bytes_read = 0;
	char *buf = NULL, **cmd = NULL, *home = getenv("HOME"), *prev_dir = NULL;

	for (i = 0; 1; i++)
	{
		cmd_prompt();
		signal(SIGINT, signal_handler);
		bytes_read = getline(&buf, &bytes, stdin);
		if (*buf == '\n')
			free(buf);
		else if (bytes_read == EOF)
			end_of_file(buf);
		else
		{
			buf[_strlen(buf) - 1] = '\0';
			cmd = create_str_cmd(buf, " \0");
			free(buf);
			if (_strcmp(cmd[0], "cd") != 0)
				cwd(cmd[1], &prev_dir, home);
			/*(cwd(cmd[1]);*/
			else if (_strcmp(cmd[0], "exit") != 0)
				quit_shell(cmd);
			else
				child_proc(cmd, av[0], ev, i);
		}
		buf = NULL, bytes = 0;
		clear_stdin_buffer();
	}
	if (bytes_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
