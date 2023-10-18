#include "shell.h"

#define BUFFER_SIZE 1024

int handle_null(size_t bytes, char **buffer);

/**
 * cwd - handles the 'cd' command and its variations
 * @token: pointer to the tokenized command
 * @prev_dir: pointer to the previous directory
 * @home: pointer to the home directory
 *
 * Return: Success (0), failure (-1)
 */
void cwd(char *token, char **prev_dir, char *home)
{
	if (token == NULL || strcmp(token, "~") == 0)
	{
		chdir(home);
	}
	else if (strcmp(token, "-") == 0)
	{
		if (*prev_dir != NULL)
		{
			chdir(*prev_dir);
		}
		else
		{
			fprintf(stderr, "No previous directory available\n");
		}
	}
	else
	{
		if (chdir(token) == 0)
		{
			*prev_dir = getcwd(NULL, BUFFER_SIZE);
			setenv("PWD", *prev_dir, 1);
		}
		else
		{
			perror("Error");
		}
	}
}

/**
 * handle_null - handles the case when the directory is NULL
 * @bytes: size of buffer
 * @buffer: buffer for current working directory
 *
 * Return: Success (0), failure (-1)
 */
int handle_null(size_t bytes, char **buffer)
{
	const char *wd;

	*buffer = malloc(bytes * sizeof(char));
	if (!*buffer)
	{
		perror("Memory allocation failed");
		return (-1);
	}
	wd = getcwd(*buffer, bytes);
	if (!wd)
	{
		perror("getcwd");
		free(*buffer);
		return (-1);
	}
	return (chdir(wd));
}

/**
 * child_proc - creates a sub process
 * @cmd: pointer to tokenized command
 * @n: pointer to the name of shell
 * @ev: pointer to the environmental variables
 * @c: count of executions
 *
 * Return: void
 */
void child_proc(char *cmd[], char *n, char *ev[], int c)
{
	int pid = 0, werror = 0, stt = 0;

	pid = fork();
	if (pid == 0)
	{
		exec(cmd, n, ev, c);
		free_cmd_mem(cmd);
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
	{
		perror("Error: ");
		free_cmd_ex(cmd);
	}
	else
	{
		werror = waitpid(pid, &stt, 0);
		if (werror < 0)
		{
			free_cmd_ex(cmd);
		}
		free_cmd_mem(cmd);
	}
}
