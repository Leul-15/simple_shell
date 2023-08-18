#include "main.h"

/**
 * _basename - Get the base name of a file path.
 * @str: The input string.
 * Return: A pointer to the base name of the path.
 */
char *_basename(const char *str)
{
	char *found = _strrchr(str, '/');

	if (found && *found == '/')
		return (++found);
	else
		return ((char *)str);
}

/**
 * _strlen - Calculate the length of a string.
 * @s: The input string.
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
	int i = 0;

	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

/**
 * _strncpy - Copy up to n characters from src to dest.
 * @dest: The destination buffer.
 * @src: The source string.
 * @n: The maximum number of characters to copy.
 * Return: A pointer to the destination buffer.
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	char *ptr = dest;

	if (!ptr)
	{
		return (NULL);
	}

	while (*src && n--)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (ptr);
}

/**
 * _strncmp - Compare the first n characters of two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The number of characters to compare.
 * Return: 0 if strings are equal, or the difference between
 * the first differing characters.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	do {
		if (*s1 != *s2++)
			return (*s1 - *--s2);
		if (*s1++ == 0)
			break;
	} while (--n != 0);
	return (0);
}

/**
 * _strcpy - Copy a source string to a destination string.
 * @dest: The destination buffer.
 * @src: The source string.
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
	const size_t len = _strlen(src);

	_memcpy(dest, src, len + 1);
	return (dest);
}
