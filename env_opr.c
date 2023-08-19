#include "shell.h"

/**
 * _getenv - get a path from environ
 * @name: name of path
 * Return: found path or NULL
 */
char *_getenv(const char *name)
{
	int len;
	const char *np;
	char **p, *c;

	if (!name || !environ)
		return (NULL);

	for (np = name; *np && *np != '='; ++np)
		continue;

	len = np - name;
	for (p = environ; (c = *p) != NULL; ++p)
	{
		if (_strncmp(c, name, len) == 0 && c[len] == '=')
			return (c + len + 1);
	}
	return (NULL);
}
