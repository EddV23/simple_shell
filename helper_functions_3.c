#include "shell.h"

/**
 * _strcat - Concatenates or appends the string pointed by src
 *           to the string pointed by dest, and adds
 *           the terminating null byte (\0),
 * @dest: the destination string
 * @src: the source string to be appended
 * Return: the pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *result = dest;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}
	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (result);
}

/**
 * _strncmp - compares two strings using defined size n
 * @str1: the first string
 * @str2: the second string
 * @n: size of character to compare
 *
 * Return: O for match, 1 otherwise
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL)
		return (-1);
	i = 0;
	while (i < n && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strcpy - copies the string pointed to by src,
 *           including the terminating null byte (\0)
 *           to the buffer pointed to by dest
 * @dest: the destination buffer
 * @src: the source string to be copied
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - this duplicates a string
 * @str: the input string
 *
 * Return: result of duplicated string
 */
char *_strdup(char *str)
{
	size_t size, i;
	char *result;

	size = _strlen(str);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	for (i = 0; i <= size; i++)
		result[i] = str[i];
	return (result);
}

/**
 * _strchr - find characters in a string
 * @str: the input str
 * @c: the character to search from the string
 *
 * Return: pointer to the character of the string
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			break;
	} while (*str++);
	return (str);
}
