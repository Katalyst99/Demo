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
	char *token = NULL, **tok_arr = NULL;
	int tks = 0, i, j;
	char *dlimit = " \n";

	if (line == NULL)
	{
		return (NULL);
	}
	lcpy = _strdup(line);

	token = strtok(line, dlimit);
	while (token)
	{
		token = strtok(NULL, dlimit);
		tks++;
	}
	tks++;

	tok_arr = malloc(sizeof(char *) * tks);
	if (tok_arr == NULL)
	{
		free(lcpy);	
		return (NULL);
	}

	token = strtok(lcpy, dlimit);
	for (i = 0; token; i++)
	{
		tok_arr[i] = malloc(sizeof(char) * (_strlen(token)));
		if (tok_arr[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(tok_arr[j]);
			}
			free(lcpy);
			free(tok_arr);
			return (NULL);
		}
		tok_arr[i] = _strdup(token);
		token = strtok(NULL, dlimit);
	}
	tok_arr[i] = NULL;
	free(lcpy);
	return (tok_arr);
}
