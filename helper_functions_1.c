#include "shell.h"

/**
 * _strncpy - Copies appends the string pointed by src
 *            to the string pointed by dest
 *            using at most n bytes from src
 * @dest: the destination string
 * @src: the source string to be copied
 * @n: the maximum number of bytes to be copied from src
 * Return: the pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: negative if str1 is less than str2
 *         0 if str1 is equal to str2
 *         positive if str1 is greater than str2
 */
int _strcmp(char *str1, char *str2)
{
	int result = 0, i;
	int a = _strlen(str1), b = _strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (a != b)
		return (1);
	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			result = str1[i] - str2[i];
			break;
		}
		else
			continue;
	}
	return (result);
}

/**
 * len_int - find the length of an integer
 * @n: the input integer to be evaluated
 *
 * Return: the length of the integer
 */
int len_int(int n)
{
	int length;

	for (length = 0; n != 0; length++)
		n /= 10;
	return (length);
}

/**
 * _atoi - converts a string to an integer
 * @s: the input string
 *
 * Return: the integer value converted from the string
 */
int _atoi(char *s)
{
	int sign = 1, i = 0, result = 0;

	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + sign * (s[i] - '0');
		i++;
	}
	return (result);
}

/**
 * _itoa - this convert an integer to a character
 * @n: the input integer to be converted
 *
 * Return: pointer to the character
 */
char *_itoa(unsigned int n)
{
	int length = 0, i = 0;
	char *c;

	length = len_int(n);
	c = malloc(length + 1);
	if (!c)
		return (NULL);
	*c = '\0';
	for (i = 0; n / 10; i++)
	{
		c[i] = (n % 10) + '0';
		n /= 10;
	}
	c[i] = (n % 10) + '0';
	rev_arr(c, length);
	c[i + 1] = '\0';

	return (c);
}
