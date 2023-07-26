#include "main.h"

/**
 * main - shell entry point
 * Return: Always 0
 */
int main(int __attribute__((unused))argc, char __attribute__((unused))**argv)
{
	size_t i = 0;
	char *lineptr = NULL;
	char **args;
	ssize_t rc = 0;
	int r_status = 0;


	while (1)
	{
		if(isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		rc = getline(&lineptr, &i, stdin);
		if (rc == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(lineptr);
			break;
		}

		if (_strcmp(lineptr, "exit") == 0)
		{
			exit_sshell();
		}

		if (_strcmp(lineptr, "env") == 0)
		{
			print_env();
		}

		args = split_tok(lineptr, rc);
		if (args[0] != NULL)
		{
			r_status = exec(args);
		}
		else
		{
			perror ("Error");
		}
		free(args);
	}
	return (r_status);
}

/**
 * exit_sshell - exits the simple shell
 */
void exit_sshell(void)
{
	exit(0);
}
