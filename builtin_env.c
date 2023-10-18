#include "shell.h"

/**
 * sh_setenv - sets or updates the value of an environment variable
 * @variable: the name of the environment variable
 * @value: the value to assign to the environment variable
 * @overwrite: flag indicating whether to overwrite an existing variable
 *
 * Return: 0 on success, -1 on failure
 */
int sh_setenv(char *variable, char *value, int overwrite)
{
	if (setenv(variable, value, overwrite) != 0)
	{
		fprintf(stderr, "setenv: Error setting the environment variable\n");
		return (-1);
	}
	return (0);
}

/**
 * sh_unsetenv - unsets an environment variable
 * @variable: the name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int sh_unsetenv(char *variable)
{
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "unsetenv: Error unsetting the environment variable\n");
		return (-1);
	}
	return (0);
}
