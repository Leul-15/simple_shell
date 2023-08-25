#include "shell.h"

/**
 * main - entry point for the shell
 * @ac: unused argument count
 * @av: argument vector
 * Return: EXIT_SUCCESS always
 */
int main(int __attribute__((unused)) ac, char **av)
{
	sh_t shell;
	char *name = av[0];

	shloop(&shell, name);

	return (EXIT_SUCCESS);
}
