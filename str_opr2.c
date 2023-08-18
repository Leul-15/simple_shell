#include "main.h"


/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: An integer less than, equal to, or greater than zero if s1 is
 * found, respectively,
 * to be less than, to match, or be greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
		{
			break;
		}
		s1++;
		s2++;
	}

	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

/**
 * _strchr - Locate a character in a string.
 * @str: The string to search in.
 * @c: The character to search for.
 * Return: A pointer to the first occurrence of the character in the
 * string, or NULL if the character is not found.
 */
char *_strchr(const char *str, char c)
{
	while (*str != (char)c)
	{
		if (!*str++)
		{
			return (NULL);
		}
	}
	return ((char *)str);
}

/**
 * _strrchr - Locate the last occurrence of a character in a string.
 * @str: The string to search in.
 * @c: The character to search for.
 * Return: A pointer to the last occurrence of the character in the
 * string, or NULL if the character is not found.
 */
char *_strrchr(const char *str, int c)
{
	char *found = NULL;

	do {
		if (*str == c)
			found = (char *)str;
	} while (*str++);
	return (found);
}

/**
 * _strncat - Concatenate two strings, limited by n bytes.
 * @s1: The destination string.
 * @s2: The source string to concatenate.
 * @n: The maximum number of bytes to concatenate from s2.
 * Return: A pointer to the destination string.
 */
char *_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int len1 = _strlen(s1);
	unsigned int len2 = _strlen(s2);

	if (len2 < n)
		_strcpy(&s1[len1], s2);
	else
	{
		_strncpy(&s1[len1], s2, n);
		s1[len1 + n] = '\0';
	}
	return (s1);
}

/**
 * _strcat - Concatenate two strings.
 * @str: The destination string.
 * @cat: The source string to concatenate.
 * Return: A pointer to the destination string.
 */
char *_strcat(char *str, const char *cat)
{
	char *cated = str;

	for (; *str; ++str)
		;
	while ((*str++ = *cat++))
		;
	return (cated);
}
