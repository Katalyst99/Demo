#include "main.h"
/**
 * split_tok - splits string into an array of tokens
 * @line: The line of text.
 * @nbytes: The number of bytes
 * Return: Array of pointers to the tokens in line.
 */
char **split_tok(char *line, int nbytes)
{
	char *lcpy;
	char *token, **tok_arr;
	int tks = 0, i = 0;
	char *dlimit = " \n";

	if (line == NULL)
	{
		return (NULL);
	}
	lcpy = malloc(sizeof(char) * nbytes);
	_strcpy(lcpy, line);

	token = strtok(line, dlimit);
	while (token)
	{
		token = strtok(NULL, dlimit);
		tks++;
	}
	tks++;

	tok_arr = malloc(sizeof(char) * tks);
	if (tok_arr == NULL)
	{
		return (NULL);
	}

	token = strtok(lcpy, dlimit);
	for (i = 0; token; i++)
	{
		tok_arr[i] = malloc(sizeof(char) * (_strlen(token)));
		if (tok_arr[i] == NULL)
		{
			return (NULL);
		}
		_strcpy(tok_arr[i], token);
		token = strtok(NULL, dlimit);
	}
	tok_arr[i] = NULL;
	return (tok_arr);
}
