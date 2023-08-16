#include "main.h"

/**
 * get_path - look for the path of a command
 * @cmd: The command
 * Return: The path of a command
 */
char *get_path(char *cmd)
{
	char *p = _getenv("PATH"),  *p_cpy = _strdup(p), *p_tkn, *p_file;
	int c_len, d_len;
	struct stat buff;

	if (p != NULL)
	{
		c_len = _strlen(cmd);
		p_tkn = strtok(p_cpy, ":");
		while (p_tkn)
		{
			d_len = _strlen(p_tkn);
			p_file = malloc(c_len + d_len + 2);
			_strcpy(p_file, p_tkn);
			_strcat(p_file, "/");
			_strcat(p_file, cmd);
			_strcat(p_file, "\0");

			if (stat(p_file, &buff) == 0)
			{
				free(p_cpy);
				return (p_file);
			}
			free(p_file);
			p_tkn = strtok(NULL, ":");
		}
		free(p_cpy);
		if (stat(cmd, &buff) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}
