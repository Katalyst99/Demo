#include "main.h"

/**
 * exec - function to execute commands
 * @args: The arguments
 * Return: Always 0 success
 */
int exec(char **args)
{
	char *r_cmd;
	pid_t c_pid;
	int status;

	r_cmd = get_path(args[0]);
	if (r_cmd == NULL)
	{
		return (-1);
	}

	c_pid = fork();
	if (c_pid == 0)
	{
		if (execve(r_cmd, args, environ) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		waitpid(c_pid, &status, 0);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
		}
	}
	return (status);
}
