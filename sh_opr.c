#include "shell.h"

/**
 * init_sh - initialize sh struct
 * @sh: sh struct
 */
void init_sh(sh_t *sh)
{
	int i = PATH_MAX;

	while (i >= 0)
	{
		sh->argv[i] = NULL;
		sh->lineptr[i] = '\0';
		sh->exe[i] = '\0';
		i--;
	}
}

/**
 * shloop - shell loop
 * @shell: sh struct storing all our data
 * @av: argument value to store shell name
 */
void shloop(sh_t *shell, char *av)
{
	pid_t child_pid = -1;
	int status = 0;

	do {
		init_sh(shell);
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "$ ", 2);

		status = readline(shell);
		if (status)
			break;

		tokenizer(shell, DELIM);
		if (*shell->argv == NULL)
			continue;

		status = findexe(shell);
		if (status)
			continue;

		if (_strcmp(shell->argv[0], "exit") == 0)
			break;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			break;
		}
		if (child_pid == 0)
		{
			if (execve(shell->exe, shell->argv, environ) == -1)
			{
				perror(av);
				break;
			}
		}
		waitpid(child_pid, &status, WUNTRACED);
	} while (1 && isatty(STDIN_FILENO));
}

/**
 * readline - read input from the command line
 * @shell: sh struct storing all data
 * Return: -1 on fail 0 on success
 */
int readline(sh_t *shell)
{
	char *read = NULL;
	ssize_t bytes_read;
	size_t n = 0;
	int i = 0;

	bytes_read = getline(&read, &n, stdin);
	if (feof(stdin))
	{
		free(read);
		write(STDIN_FILENO, "\n", 1);
		return (-1);
	}

	if (bytes_read == -1)
	{
		free(read);
		perror("getline");
		return (-1);
	}
	else
	{
		while (read[i])
		{
			shell->lineptr[i] = read[i];
			i++;
		}
		free(read);
	}
	return (0);
}
