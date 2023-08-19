#include "shell.h"

/**
 * _memcpy - copy string buffer from src to dest up to n
 * @dest: destination pointer
 * @src: source pointer
 * @len: up to this len
 * Return: destination addres
 */
char *_memcpy(char *dest, const char *src, int len)
{
	char *da = dest;

	while (len-- > 0)
		*dest++ = *src++;
	return (da);
}

/**
 * tokenizer - store string tokens to an arg list
 * @shell: sh struct storing all our data
 * @delim: separation
 */
void tokenizer(sh_t *shell, char *delim)
{
	int position = 0;
	char *token = NULL;

	token = strtok(shell->lineptr, delim);
	while (token)
	{
		shell->argv[position] = token;
		position++;
		if (position >= PATH_MAX)
			return;
		token = strtok(NULL, delim);
	}
	shell->argv[position] = NULL;
}
