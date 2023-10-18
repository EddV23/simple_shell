#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @s: the input string
 *
 * Return: the integer value converted from the string
 */
int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int result = 0;
	char digit = 0;

	if (sign < 0)
	{
		result = (-1 * (result));
	}
	if (s == NULL)
	{
		return (0);
	}
	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] < '0' || s[i] > '9')
		{
			if (digit == 1)
				break;
		}
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = 1;
			result = result * 10 + (s[i] - '0');
		}
	}
	return (result);
}

/**
 * _strcmp - Compares two strings
 * @s1: the first string
 * @s2: the second string
 * Return: negative if s1 is less than s2
 *         0 if s1 is equal to s2
 *         positive if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i;

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

/**
 * _strcpy - Copies the string pointed to by src,
 *           including the terminating null byte (\0)
 *           to the buffer pointed to by dest
 * @dest: the destination buffer
 * @src: the source string to be copied
 * Return: the pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	char *start_dest = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (start_dest);
}

/**
 * _strlen  - returns the length of a string
 * @s : input string whose length will be returned
 * Return: length of string
 */
unsigned int _strlen(char *s)
{
	unsigned int i = 0;

	/*for (i = 0; s[i] != '\0'; i++);*/
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcat - Concatenates or appends the string pointed by src
 *           to the string pointed by dest, and adds
 *           the terminating null byte (\0),
 * @dest: the destination string
 * @src: the source string to be appended
 * Return: the pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
		dest++;
	*dest++ = '/';
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	return (result);
}
