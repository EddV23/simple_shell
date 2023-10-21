#include "shell.h"

/**
 * file_p - creates sub process for file
 * @buf: the file's line
 * @c: counts of executions
 * @myfile: the file descriptor
 * @ev: pointer to the environmental variables
 *
 * Return : void
 */
void file_p(char *buf, int c, FILE *myfile, char *ev[])
{
	char **cmd;
	int st = 0;

	cmd = crt_token(buf);

	if (builtin_ch(cmd) == 0)
	{
		st = builtin_hd(cmd, st);
		free(cmd);
	}
	else if (_strncmp(cmd[0], "exit", 4) == 0)
		file_exit(cmd, buf, myfile);
	else
	{
		st = child_proc(cmd, buf, c, ev);
		free(cmd);
	}
}

/**
 * file_r - this reads a files commands
 * @n: the name of the file
 * @ev: pointer to the environmental variables
 *
 * Return: void
 */

void file_r(char *n, char *ev[])
{
	FILE *myfile;
	int i = 0;
	char *buf = NULL;
	size_t size = 0;

	myfile = fopen(n, "r");
	if (myfile == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	while ((getline(&buf, &size, myfile)) != -1)
	{
		i++;
		file_p(buf, i, myfile, ev);

	}
	if (buf)
		free(buf);
	fclose(myfile);
	exit(0);
}

/**
 * file_exit - to close a file
 * @buf: the file's line
 * @cmd: pointer to tokenized command
 * @myfile: the file descriptor
 *
 * Return : void
 */
void file_exit(char *cmd[], char *buf, FILE *myfile)
{
	int stt, i = 0;

	if (cmd[1] == NULL)
	{
		free(buf);
		free(cmd);
		fclose(myfile);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("Invalid input");
		}
	}
	stt = _atoi(cmd[1]);
	free(buf);
	free(cmd);
	fclose(myfile);
	exit(stt);
}

/**
 * my_hist - writes the user's command history
 * @n: the input buffer
 *
 * Return: 0 for Succes
 */
int my_hist(char *n)
{
	char *name = ".my_history";
	ssize_t myfile, mywrite;
	int size = 0;

	if (!name)
		return (-1);
	myfile = open(name, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (myfile < 0)
		return (-1);
	if (n)
	{
		while (n[size])
		{
			size++;
		}
		mywrite = write(myfile, n, size);
		if (mywrite < 0)
			return (-1);
	}
	return (1);
}
