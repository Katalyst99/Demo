#include "main.h"

/**
 * _getenv - Function that searches the environment for a variable
 * @name: The name of the environment variable to search for.
 * Return: Pointer to the value of the environment variable
 */
char *_getenv(char *name)
{
	int i = 0, j;

	while (environ[i])
	{
		j = _strcmp(environ[i], name);
		if (j == 0)
		{
			return (environ[i] + 1);
		}
		i++;
	}
	return (NULL);
}

/**
 * print_env - prints the environment
 */
void print_env(void)
{
	int i;
	int file_d = STDOUT_FILENO;

	for (i = 0; environ[i]; i++)
	{
		if (environ[i])
		{
			write(file_d, environ[i], _strlen(environ[i]));
			write(file_d, "\n", 1);
		}
	}
}
