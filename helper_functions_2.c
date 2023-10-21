#include "shell.h"

/**
 * _strlen  - returns the length of a string
 * @s : input string whose length will be returned
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _isalpha - evaluates for an alphabet characte
 * @c: the character to be checked
 * Return: 1 if is an alphabet
 */
int _isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	else
		return (0);
}

/**
 * rev_arr - this reverses an array
 * @arr: array
 * @length: the length Of Array
 *
 * Return: Void(Reverse Array)
 */
void rev_arr(char *arr, int length)
{
	int i = 0;
	char temp;

	while (i < (length / 2))
	{
		temp = arr[i];
		arr[i] = arr[(length - 1) - i];
		arr[(length - 1) - i] = temp;
		i++;
	}
}

/**
 * _puts  - prints a string, followed by a new line to stdout
 * @str : input string to be printed
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
