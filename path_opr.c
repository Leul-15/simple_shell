#include "shell.h"

/**
 * findexe - find excutable stored in argv[0]
 * @shell: sh struct storing all data
 * Return: 0 on success -1 on fail
 */
int findexe(sh_t *shell)
{
	if (_strchr(shell->argv[0], '/') != NULL)
	{
		if (realpath(shell->argv[0], shell->exe) == NULL)
			return (-1);
		if (isexe(shell->exe))
			return (0);
	}

	pathof(shell, _basename(shell->argv[0]));
	return (0);
}

/**
 * isexe - check if file or directory is excutable or
 * readable
 * @filename: file or directory name to check
 * Return: non zero on success 0 on fail
 */
int isexe(const char *filename)
{
	int result;
	struct stat statinfo;

	result = stat(filename, &statinfo);
	if (result < 0)
		return (0);
	if (!S_ISREG(statinfo.st_mode))
		return (0);

	if (statinfo.st_uid == geteuid())
		return (statinfo.st_mode & S_IXUSR);
	if (statinfo.st_gid == getegid())
		return (statinfo.st_mode & S_IXGRP);
	return (statinfo.st_mode & S_IXOTH);
}

/**
 * pathof - find a path of excutable file
 * @shell: sh struct storing all data
 * @exe: excutable to look for
 * Return: non zero on success 0 on fail
 */
int pathof(sh_t *shell, const char *exe)
{
	char *searchpath;
	char *beg, *end;
	int stop = 0, found = 0;
	int len;

	searchpath = _getenv("PATH");
	if (searchpath == NULL)
		return (0);
	if (_strlen(searchpath) <= 0)
		return (0);

	beg = searchpath;
	do {
		end = _strchr(beg, ':');
		if (end == NULL)
		{
			stop = 1;
			_strncpy(shell->exe, beg, PATH_MAX);
			len = _strlen(shell->exe);
		}
		else
		{
			_strncpy(shell->exe, beg, end - beg);
			shell->exe[end - beg] = '\0';
			len = end - beg;
		}
		if (shell->exe[len - 1] != '/')
			_strcat(shell->exe, "/");
		_strncat(shell->exe, exe, PATH_MAX - len);
		found = isexe(shell->exe);
		if (!stop)
			beg = end + 1;
	} while (!stop && !found);

	return (found);
}
