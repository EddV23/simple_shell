#include "shell.h"

/**
 * main - Entry point, runs the simple shell
 * @ac: argument count
 * @av: arguments vector
 *
 * Return: Always 0 (Success)
 */
int main(int ac, char *av[])
{
	int i = 0, stt = 0;
	char *buf, **tok;

	(void)ac;

	if (av[1] != NULL)
		file_r(av[1], av);
	signal(SIGINT, signal_handler);
	while (1)
	{
		i++;
		if (isatty(STDIN_FILENO))
			cmd_prompt();
		buf = _getline();
		/*print("Received input: %s\n", (buf != NULL) ? buf : "NULL");*/
		/*if (buf == NULL || buf[0] == '\0')*/
		if (buf[0] == '\0')
		{
			/*if (buf != NULL)*/
			/*free(buf);*/
			/*print("Empty input detected. Skipping...\n");*/
			continue;
		}
		my_hist(buf);
		tok = crt_token(buf);
		if (_strcmp(tok[0], "exit") == 0)
			quit_shell(tok, buf, av, i);
		else if (builtin_ch(tok) == 0)
		{
			stt = builtin_hd(tok, stt);
			mem_clear(tok, buf);
			continue;
		}
		else
			stt = child_proc(tok, buf, i, av);
		mem_clear(tok, buf);
	}
	return (1);
}
