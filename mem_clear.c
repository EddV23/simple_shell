#include "shell.h"

/**
 * free_cmd_mem - frees all memory allocated to a command
 * @cmd: pointer to allocated memory to be freed
 *
 * Return: void
 */
void free_cmd_mem(char *cmd[])
{
	size_t i = 0;

	if (cmd == NULL)
		return;

	for (i = 0; cmd[i]; i++)
		free(cmd[i]);

	if (cmd[i] == NULL)
		free(cmd[i]);
	free(cmd);
}


/**
 * free_cmd_ex - frees all the memory allocated and exits
 * @cmd: pointer to the allocated command memory to be freed
 *
 * Return: void
 */
void free_cmd_ex(char **cmd)
{
	size_t i = 0;

	if (cmd == NULL)
		return;

	for (i = 0; cmd[i]; i++)
		free(cmd[i]);

	if (cmd[i] == NULL)
		free(cmd[i]);
	free(cmd);
	exit(EXIT_FAILURE);
}
